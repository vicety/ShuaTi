#ifndef PIXMAP_H
#define PIXMAP_H

#include<bits/stdc++.h>
#include <QObject>
#include<windows.h>
#include<QPixmap>

typedef struct PixMapRGB{
    BYTE b;
    BYTE g;
    BYTE r;
    PixMapRGB(){b = 255, g = 255, r = 255;}
    PixMapRGB(BYTE &_r, BYTE &_g, BYTE &_b){
        r = _r, g = _g, b = _b;
    }
}_RGB;


class PixMap : public QObject
{
    Q_OBJECT
public:
    static const char* tmpFileName;  // 缓存的图像名

    PixMap();
    PixMap(const char* src);
    PixMap(PixMap *& _img);
    void assign(PixMap *& _img);
    ~PixMap();
    void init();

    // IO 操作
    bool load(const char* src);
    bool save(const char* dst = tmpFileName);

    // 无参转换
    bool toGrey8();  // 转为8位灰度图
    bool toGrey24();  // 转为24位灰度图
    bool mirror();  // 镜像
    bool clockWise90();  // 顺时针旋转，没写到GUI上，跳过就好
    bool smooth();  // 平滑
    bool black_white();  // 转换为8位黑白图
    bool black_white_2();  // 转换为2位黑白图


    // 有参转换
    bool extractBorder(QWidget* parent, int diff);  // 素描模式
    bool changeContrast(QWidget* parent, int factor);  // 对比度
    bool changeLightness(QWidget *parent, int factor);  // 亮度

    // public 数据成员
    QPixmap Qimg;
    std::map<std::string, bool (PixMap::*)()> execMap;
    std::map<std::string, bool (PixMap::*)(QWidget*, int)> execMapWithPara;

signals:
    void changeImg(const char*);
    void newImg();
    void log(const char*, int = 3000);
private:
    // 像素操作
    void swapPixel(_RGB* a, _RGB* b);
    void setPixel(_RGB* tar, _RGB* src, int y, int x, std::function<_RGB(_RGB)> mapping = nullptr);
    _RGB* getLine(int line);
    _RGB* getPixel(int y, int x);
    BYTE getPixelForGrey(int y, int x);

    // 特殊操作
    int getDiff(_RGB tar, int r, int g, int b);
    void initEightBitPtr();
    void initImgPtr();
    bool validateAvailability(int bit);

    // private数据成员
    BITMAPFILEHEADER fileHeader; // 文件头
    BITMAPINFOHEADER infoHeader;
    int height, width; // 图片宽高
    int bitsOffset;  // 从文件开始位置到存储像素位置的地址偏移量
    int colorBitCount;  // 图片位数
    int fixedByteForBW;  // 修正后的黑白图的每行字节数
    int fixedByteFor8;  // 修正后的8位图的每行字节数
    _RGB* img;  // 像素信息存储位置
    BYTE* imgGrey;  // 8位图片存储位置
    RGBQUAD* palette;  // 调色板
};

#endif // PIXMAP_H
