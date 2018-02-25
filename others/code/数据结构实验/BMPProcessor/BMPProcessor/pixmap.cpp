#include<bits/stdc++.h>
#include<windows.h>
#include<QDebug>
#include "pixmap.h"
#include<QCoreApplication>
#include<QProgressDialog>
using namespace std;

// 非常整形静态成员，只能在类外初始化 这里是临时文件的名称
const char* PixMap::tmpFileName = "tmp.bmp";

PixMap::PixMap(){
    // 为了在load中能先删除上次的空间 在初始化中先申请一个空间
    img = new _RGB[1];
    imgGrey = new BYTE[1];
    img = nullptr;
    imgGrey = nullptr;
    palette = nullptr;
    init();
}

// 从文件读入
PixMap::PixMap(const char *src){
    img = new _RGB[1];
    imgGrey = new BYTE[1];
    palette = nullptr;
    if(!load(src)) img = nullptr;
    init();
}

// 用于撤回操作的复制构造函数
PixMap::PixMap(PixMap *&_img){
    // 还应该加一个禁止创建什么的
    // 之前忘了把头信息复制过来了…… 绝望
    assign(_img);
    init();
}

// 复制构造函数的具体拷贝过程
void PixMap::assign(PixMap *& _img){
    initImgPtr();
    initEightBitPtr();
    if(_img->infoHeader.biBitCount == 24){
        img = new _RGB[_img->height * _img->width];
        memcpy(img, _img->img, sizeof(_RGB) * _img->width * _img->height);
    }
    else if(_img->infoHeader.biBitCount == 8){
        cerr<<"when copying to oriimg here\n";
        palette = new RGBQUAD[256];
        imgGrey = new BYTE[_img->width * _img->height];
        memcpy(palette, _img->palette, sizeof(RGBQUAD) * 256);
        memcpy(imgGrey, _img->imgGrey, sizeof(BYTE) * _img->width * _img->height);
    }
    height = _img->height, width = _img->width;
    cout<<height<<" "<<width<<endl;
    fileHeader = _img->fileHeader, infoHeader = _img->infoHeader;
    bitsOffset = _img->bitsOffset, colorBitCount = _img->colorBitCount;
    Qimg = _img->Qimg;
}

// 析构时释放所有申请空间
PixMap::~PixMap(){
    initImgPtr();
    initEightBitPtr();
}

// 建立字符串与函数指针的关联
void PixMap::init(){
    execMap[string("24bitGrey")] = toGrey24;
    execMap[string("8bitGrey")] = toGrey8;
    execMap[string("black_white")] = black_white;
    execMap[string("smooth")] = smooth;
    execMap[string("mirror")] = mirror;
    execMap[string("black_white_2")] = black_white_2;
    // execMap[string("clockWise90")] = clockWise90;
    execMapWithPara[string("extract border")] = extractBorder;
    execMapWithPara[string("lightness")] = changeLightness;
    execMapWithPara[string("contrast")] = changeContrast;

}

// 分为8位和24位两种方案读取图片
bool PixMap::load(const char *src){
    initImgPtr();
    initEightBitPtr();
    cerr<<"at load here\n";
    FILE* filePtr = fopen(src, "rb");
    // 文件格式检查
    if(!filePtr){
        emit log("invalid path");
        return false;
    }
    fread(&fileHeader, 1, sizeof(BITMAPFILEHEADER), filePtr);
    if(0x4d42 != fileHeader.bfType){
        emit log("invalid format");
        return false;
    }
    // 读取文件头并作出判断
    fread(&infoHeader, 1, sizeof(BITMAPINFOHEADER), filePtr);
    height = infoHeader.biHeight, width = infoHeader.biWidth;
//    fixedByteForBW = ((width * height / 8) + 7) / 8 * 8;
//    fixedByteFor8 = fixedByteForBW * 8;
    if(infoHeader.biBitCount == 24){
        img = new _RGB[height * width];
        fread(img, 1, sizeof(_RGB) * (width * height), filePtr);

    }
    else if(infoHeader.biBitCount == 8){
        emit log("reading 8 bit bmp");
        palette = new RGBQUAD[256];
        fread(palette, 1, sizeof(RGBQUAD) * 256, filePtr);
        imgGrey = new BYTE[height * width];
        fread(imgGrey, 1, sizeof(BYTE) * (width * height), filePtr);
    }
    bitsOffset = fileHeader.bfOffBits;
    colorBitCount = infoHeader.biBitCount;
    fclose(filePtr);
    // 向GUI发送更新图片的事件通知
    emit changeImg(src);
    cerr<<"here3\n";
    emit newImg();
    cerr<<"here4\n";
    return true;
}

// 保存图片 分为8位和24位两种情况
bool PixMap::save(const char *dst){
    FILE* toSavePtr = fopen(dst, "wb");
    cerr<<"at save here\n";
    if(infoHeader.biBitCount == 8){
        fwrite(&fileHeader, 1, sizeof(BITMAPFILEHEADER), toSavePtr);
        fwrite(&infoHeader, 1, sizeof(BITMAPINFOHEADER), toSavePtr);
        fwrite(palette, 1, sizeof(RGBQUAD) * 256, toSavePtr);
        fwrite(imgGrey, 1, sizeof(BYTE)*(height*width), toSavePtr);
        cerr<<"at save here\n";
    }

    // 24 位
    else if(infoHeader.biBitCount == 24){
        fwrite(&fileHeader, 1, sizeof(BITMAPFILEHEADER), toSavePtr);
        fwrite(&infoHeader, 1, sizeof(BITMAPINFOHEADER), toSavePtr);
        fwrite(img, 1, sizeof(_RGB)*(height*width), toSavePtr);
    }
    else{
        emit log("saving 2bit bmp");
        fwrite(&fileHeader, 1, sizeof(BITMAPFILEHEADER), toSavePtr);
        fwrite(&infoHeader, 1, sizeof(BITMAPINFOHEADER), toSavePtr);
        fwrite(palette, 1, sizeof(RGBQUAD) * 2, toSavePtr);
        fwrite(imgGrey, 1, sizeof(BYTE)*(4 * ((width * infoHeader.biBitCount + 31) / 32) * height), toSavePtr);
    }
    fclose(toSavePtr);
    emit log(((string("saved successfully at ")+string(dst))).c_str());
    return true;
}

// 24位图转为8位灰度图
bool PixMap::toGrey8(){
    if(infoHeader.biBitCount == 8){
        emit log("已为8位灰度图\n");
        return false;
    }
    initEightBitPtr();
    imgGrey = new BYTE[width * height];
    palette = new RGBQUAD[256];
    for(int i = 0; i < 256; i++){
        palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = i;
        palette[i].rgbReserved = 0;
    }
    infoHeader.biBitCount = 8; // bit offset 不变？
    fileHeader.bfOffBits = 1078;
    fileHeader.bfSize = 1078 + width * height;
    _RGB* tmp;
    for(int i = 1; i <= height; i++){
       for(int j = 1; j <= width; j++){
           tmp = getPixel(i, j);
           imgGrey[(height - i) * width + j - 1] =
                   tmp->r * 0.299 + tmp->g * 0.587 + tmp->b * 0.114;
       }
   }
   cerr<<"before saving\n";
   save();
   // infoHeader.biBitCount = 24; // 主要以24位图像为基准进行操作
   // delete imgGrey;
   emit changeImg(tmpFileName);
   return true;
}

// 24位彩色图转为灰度图
bool PixMap::toGrey24(){
    if(!validateAvailability(24)) return false;
    cout<<"in grey\n";
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= width; j++){
            // cout<<i<<" "<<j<<endl;
            _RGB* pixel = getPixel(i, j);
            short grey = pixel->r * 0.299 + pixel->g * 0.587 + pixel->b * 0.114;
            pixel->r = grey;
            pixel->g = grey;
            pixel->b = grey;
        }
    }
    cout<<"out grey before save\n";
    save();
    emit changeImg(tmpFileName);
    return true;
}

// 平滑操作 对相邻像素的作用权值做了一些修改
bool PixMap::smooth(){
    if(!validateAvailability(24)) return false;
    _RGB* newimg = new _RGB[width * height];
    _RGB* line1;
    _RGB* line2 = getLine(1);
    _RGB* line3 = getLine(2);
    for(int y = 2; y < height; y++){
        line1 = line2;
        line2 = line3;
        line3 = getLine(y+1);
        for(int x = 2; x < width; x++){
            setPixel(newimg, img, y, x, [&](_RGB useless) -> _RGB{
                _RGB tmp;
                tmp.r = (line1[x-1].r/1.414 + line1[x].r + line1[x+1].r/1.414
                        +line3[x-1].r/1.414 + line3[x].r + line3[x+1].r/1.414
                        +line2[x-1].r + line2[x].r * 2 + line2[x+1].r) / 8.8289;
                tmp.g = (line1[x-1].g/1.414 + line1[x].g + line1[x+1].g/1.414
                        +line3[x-1].g/1.414 + line3[x].g + line3[x+1].g/1.414
                        +line2[x-1].g + line2[x].g * 2 + line2[x+1].g) / 8.8289;
                tmp.b = (line1[x-1].b/1.414 + line1[x].b + line1[x+1].b/1.414
                        +line3[x-1].b/1.414 + line3[x].b + line3[x+1].b/1.414
                        +line2[x-1].b + line2[x].b * 2 + line2[x+1].b) / 8.8289;
                return tmp;
            });
        }
    }
    // 补全外围空白
    for(int i = 1; i <= width; i++) setPixel(newimg, img, 1, i);
    for(int i = 1; i <= width; i++) setPixel(newimg, img, height, i);
    for(int i = 2; i < height; i++) setPixel(newimg, img, i, 1);
    for(int i = 2; i < height; i++) setPixel(newimg, img, i, width);
    memcpy(img, newimg, sizeof(_RGB) * width * height);
    delete newimg;
    save();
    emit changeImg(tmpFileName);
    return true;
}

// 镜像操作
bool PixMap::mirror(){
    if(!validateAvailability(24)) return false;
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= width/2; j++){
            swapPixel(getPixel(i, j), getPixel(i, width - j + 1));
        }
    }
    save();
    emit changeImg(tmpFileName);
    return true;
}

// 8位灰度图转8位黑白图
bool PixMap::black_white(){
    if(!validateAvailability(8)) return false;
    if(palette != nullptr){
        delete palette;
        palette = nullptr;
    }
    BYTE* newImg = new BYTE[width * height];
    palette = new RGBQUAD[256];
    for(int i = 0; i < 128; i++){
        palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = 0;
        palette[i].rgbReserved = 0;
    }
    for(int i = 128; i < 256; i++){
        palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = 255;
        palette[i].rgbReserved = 0;
    }
//    infoHeader.biBitCount = 8; // bit offset 不变？
//    fileHeader.bfOffBits = 1078;
//    fileHeader.bfSize = 1078 + width * height;
//    BYTE* tmp;
    for(int i = 1; i <= height; i++){
       for(int j = 1; j <= width; j++){
//           tmp = getPixel(i, j);
           if(imgGrey[(height - i) * width + j - 1] > 127) newImg[(height - i) * width + j - 1] = 255;
           else newImg[(height - i) * width + j - 1] = 0;
       }
   }
   memcpy(imgGrey, newImg, sizeof(BYTE) * height * width);
   save();
   delete newImg;
   emit changeImg(tmpFileName);
   return true;
}

// 先不做不能被8整除
bool PixMap::black_white_2(){
    if(!validateAvailability(8)) return false;
    RGBQUAD* tmpPalette = new RGBQUAD[256];
    memcpy(tmpPalette, palette, sizeof(RGBQUAD) * 256);
    if(palette != nullptr){
        delete palette;
        palette = nullptr;
    }

    // 修改bit位数 暂时修改imgGrey
    infoHeader.biBitCount = 1;
    fileHeader.bfOffBits = 62;
    fileHeader.bfSize = 62 + 4 * ((width * infoHeader.biBitCount + 31) / 32) * height;

    palette = new RGBQUAD[2];
    palette[0].rgbBlue = palette[0].rgbGreen = palette[0].rgbRed = palette[0].rgbReserved = 0;
    palette[1].rgbBlue = palette[1].rgbGreen = palette[1].rgbRed = 255, palette[1].rgbReserved = 0;
// ((width * height) / 8 + 7) / 8 * 8;
    int bytePerLine = 4 * ((width * infoHeader.biBitCount + 31) / 32);
    int bitPerLine = bytePerLine * 8;
    int allBytesNeeded = bytePerLine * height;
    BYTE* newImg = new BYTE[allBytesNeeded];
    memset(newImg, 0, sizeof(BYTE) * allBytesNeeded);
    int allPixel = width * height;
    int lineLeft = bitPerLine - width; // 2208 - 2200
        cerr<<"here...1\n"<<allPixel<<endl;
    for(int h = 0; h < height; h++){
        for(int w = 0; w < bytePerLine - 1; w++){
            for(int i = 0; i < 8; i++){
                newImg[h * bytePerLine + w] += (imgGrey[h * width + w * 8 + i] > 127 ? 1 : 0) << (7-i);
            }
        }
    }
    cerr<<"here...1\n";
    BYTE* tmp = new BYTE[width * height];
    memcpy(tmp, imgGrey, sizeof(BYTE) * width * height);
    delete imgGrey;
    imgGrey = new BYTE[allBytesNeeded];
    memcpy(imgGrey, newImg, sizeof(BYTE) * allBytesNeeded);
    delete newImg;
    save();

    infoHeader.biBitCount = 8;
    fileHeader.bfOffBits = 1078;
    fileHeader.bfSize = 1078 + width * height;
    delete imgGrey;
    imgGrey = new BYTE[width * height];
    memcpy(imgGrey, tmp, sizeof(BYTE) * width * height);

    delete palette;
    palette = new RGBQUAD[256];
    memcpy(palette, tmpPalette, sizeof(RGBQUAD) * 256);
    delete tmpPalette;
    delete tmp;
    return true;
}

// 交换像素（24位图 以下像素操作均为对24位图的）
void PixMap::swapPixel(_RGB* a, _RGB* b){
    _RGB tmp;
    tmp.r = a->r, tmp.g = a->g, tmp.b = a->b;
    a->r = b->r, a->g = b->g, a->b = b->b;
    b->r = tmp.r, b->g = tmp.g, b->b = tmp.b;
}

// 获取指向y行x列的像素指针
_RGB* PixMap::getPixel(int y, int x){
    return &img[(height - y) * width + x - 1];
}

// 将目标像素设为原像素的某个映射 该映射可以自行指定
//  function<_RGB(_RGB)> mapping  _RGB(*mapping)(_RGB) 为什么函数指针会出错
void PixMap::setPixel(_RGB* tar, _RGB* src, int y, int x, function<_RGB(_RGB)> mapping){
    if(mapping) tar[(height - y) * width + x - 1] = mapping(src[(height - y) * width + x - 1]);
    else tar[(height - y) * width + x - 1] = src[(height - y) * width + x - 1];
}

// 素描模式
// 可以用log把delta减小，使噪点减少
bool PixMap::extractBorder(QWidget* parent, int diff){
    if(!validateAvailability(24)) return false;
    _RGB* newimg = new _RGB[width * height];
    QProgressDialog process(QObject::tr("图像处理进度"),QObject::tr("取消"),0, height-2, parent);
    process.setWindowTitle(QObject::tr("进度"));
    process.setWindowModality(Qt::WindowModal);
    process.show();
    _RGB* line1;
    _RGB* line2 = getLine(1);
    _RGB* line3 = getLine(2);
    for(int y = 2; y < height; y++){
        process.setValue(y);
        if(process.wasCanceled()) break;
        QCoreApplication::processEvents();
        line1 = line2;
        line2 = line3;
        line3 = getLine(y+1);
        for(int x = 2; x < width; x++){
            int res = 0;
            int r = line2[x].r;
            int g = line2[x].g;
            int b = line2[x].b;
            for(int i = -1;i<=1;i++) if(getDiff(line1[x+i], r, g, b) >= diff) res++;
            for(int i = -1;i<=1;i++) if(getDiff(line3[x+i], r, g, b) >= diff) res++;
            if(getDiff(line2[x+1],r,g,b)>=diff) res++;
            if(getDiff(line2[x-1],r,g,b)>=diff) res++;
            if(res>=3) setPixel(newimg, img, y, x);
        }
    }
    // 补全外围空白
    for(int i = 1; i <= width; i++) setPixel(newimg, img, 1, i);
    for(int i = 1; i <= width; i++) setPixel(newimg, img, height, i);
    for(int i = 2; i < height; i++) setPixel(newimg, img, i, 1);
    for(int i = 2; i < height; i++) setPixel(newimg, img, i, width);
    memcpy(img, newimg, sizeof(_RGB) * width * height);
    delete newimg;
    save();
    emit changeImg(tmpFileName);
    return true;
}

// 获取图像第line行第一个元素的指针
_RGB* PixMap::getLine(int line){
    return img + (height - line) * width;
}

// 获取像素间的差距大小
int PixMap::getDiff(_RGB tar,int r, int g,int b){
    double ans = 0;
    ans += pow(tar.r - r, 2);
    ans += pow(tar.g - g, 2);
    ans += pow(tar.b - b, 2);
    ans = sqrt(ans);
    return int(ans);
}

// 更改亮度
bool PixMap::changeLightness(QWidget* parent, int factor){
    if(!validateAvailability(24)) return false;
    int lookup[256];
    double _factor;
    if(factor >= 50){
        _factor = ((double)(factor - 50) / 50);
        for(int i = 0; i <= 255; i++){
            lookup[i] = pow(i, 1 - _factor) * pow(255, _factor);
        }
    }
    else{
        _factor = double(factor) / 50;
        for(int i = 0; i <= 255; i++){
            lookup[i] = i * _factor;
        }
    }
    // _RGB* newimg = new _RGB[width * height];
    QProgressDialog process(QObject::tr("图像处理进度"),QObject::tr("取消"),0, height-2, parent);
    process.setWindowTitle(QObject::tr("进度"));
    process.setWindowModality(Qt::WindowModal);
    process.show();
    for(int i = 1; i <= height; i++){
        process.setValue(i);
        if(process.wasCanceled()) break;//break应该不返回图像的
        QCoreApplication::processEvents();
        for(int j = 1; j <= width; j++){
            setPixel(img, img, i, j, [lookup](_RGB input)->_RGB{ // 无法保存更改的版本第一个参数是newimg
                _RGB output;
                output.r = lookup[input.r];
                output.g = lookup[input.g];
                output.b = lookup[input.b];
                return output;
            });
        }
    }
    save();
    emit changeImg(tmpFileName);
    return true;
}

// 更改对比度
bool PixMap::changeContrast(QWidget *parent, int factor){
    if(!validateAvailability(24)) return false;
    double _factor = (double)factor/50;
    int lookup[256];
    for(int i = 0; i <= 255; i++){
        lookup[i] = 128 + (i - 128) * _factor;
        if(lookup[i] > 255) lookup[i] = 255;
        if(lookup[i] < 0) lookup[i] = 0;
    }
    QProgressDialog process(QObject::tr("图像处理进度"),QObject::tr("取消"),0, height-2, parent);
    process.setWindowTitle(QObject::tr("进度"));
    process.setWindowModality(Qt::WindowModal);
    process.show();
    for(int i = 1; i <= height; i++){
        process.setValue(i);
        if(process.wasCanceled()) break;
        QCoreApplication::processEvents();
        for(int j = 1; j <= width; j++){
            setPixel(img, img, i, j, [lookup](_RGB input)->_RGB{
                _RGB output;
                output.r = lookup[input.r];
                output.g = lookup[input.g];
                output.b = lookup[input.b];
                return output;
            });
        }
    }
    // save(newimg);
    save();
    // delete newimg;
    emit changeImg(tmpFileName);
    return true;
}

// 顺时针旋转90°
bool PixMap::clockWise90(){
    _RGB* newimg = new _RGB[width * height];
    _RGB* tmp;
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= width; j++){
            // 就应该建一个新数组，再取代这个数组
            swapPixel(getPixel(i, j), &newimg[(width - j) * height + (height - i)]);
        }
    }
    infoHeader.biHeight = width, infoHeader.biWidth = height;
    width = infoHeader.biWidth, height = infoHeader.biHeight;
    delete img;
    img = newimg;
    save();
    emit changeImg(tmpFileName);
    return true;
}

// 初始化用于8位图的指针
void PixMap::initEightBitPtr(){
    if(!imgGrey){
        delete imgGrey;
        imgGrey = nullptr;
    }
    if(!palette){
        delete palette;
        palette = nullptr;
    }
}

// 初始化用于24位图的指针
void PixMap::initImgPtr(){
    if(!img){
        delete img;
        img = nullptr;
    }
}

// 验证当前图片是否符合将要进行的操作的前提
bool PixMap::validateAvailability(int bit){
    if(infoHeader.biBitCount == bit) return true;
    emit log("当前图片位数不适用于此操作");
    return false;
}

