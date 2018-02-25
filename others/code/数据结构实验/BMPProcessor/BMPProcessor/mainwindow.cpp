#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<pixmap.h>
#include<QLabel>
#include<QFileDialog>
#include<QPixmap>
#include<QMimeData>
#include<QDragEnterEvent>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    init();
}

// 初始化GUI
void MainWindow::init(){
    img = new PixMap();
    oriimg = nullptr;
    setAcceptDrops(true);  // 接受拖入图片
    addConncetions();  // 添加与PixMap类信号的关联
    addOperations();  // 向多选栏中添加选项
    disableButtons();  // 在图片打开前禁用大部分按钮
    ui->checkBox_sizeFixed->setChecked(true);
    initStyle();  // 初始化样式表
    imgDisplay = new QLabel(this);
    ui->scrollArea->setWidget(imgDisplay);
}

// 添加与PixMap类信号的关联
void MainWindow::addConncetions(){
    connect(img, SIGNAL(changeImg(const char*)), this, SLOT(changeImg(const char*)));
    connect(img, SIGNAL(newImg()), this, SLOT(newImg()));
    connect(ui->checkBox_sizeFixed, SIGNAL(clicked(bool)), this, SLOT(changeImgStatus()));
    connect(img, SIGNAL(log(const char*,int)), this, SLOT(log(const char*,int)));
}

// 向多选栏中添加选项
void MainWindow::addOperations(){
    ui->comboBox_operation->addItem(QString("8bitGrey"));
    ui->comboBox_operation->addItem(QString("24bitGrey"));
    ui->comboBox_operation->addItem(QString("smooth"));
    ui->comboBox_operation->addItem(QString("black_white"));
    ui->comboBox_operation->addItem(QString("black_white_2"));
    ui->comboBox_operation->addItem(QString("mirror"));
    ui->comboBox_operation->addItem(QString("extract border"));
    ui->comboBox_operation->addItem(QString("lightness"));
    ui->comboBox_operation->addItem(QString("contrast"));

//    ui->comboBox_operation->addItem(QString("clockWise90"));
}

// 初始化样式表
void MainWindow::initStyle(){
    QFile file(":/qss/psblack.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
        return;
    }
    qDebug("未能加载样式表");
}

// 在图片打开前禁用大部分按钮
void MainWindow::disableButtons(){
    ui->pushButton_convert->setDisabled(true);
    ui->pushButton_saveAs->setDisabled(true);
    ui->checkBox_sizeFixed->setDisabled(true);
    ui->pushButton_cancel->setDisabled(true);
}

// 启用按钮
void MainWindow::enableButtons(){
    ui->pushButton_convert->setDisabled(false);
    ui->pushButton_saveAs->setDisabled(false);
    ui->checkBox_sizeFixed->setDisabled(false);
    ui->pushButton_cancel->setDisabled(false);
}

// 释放原图和修改过的图这两个指向PixMap类的指针
MainWindow::~MainWindow(){
    delete ui;
    if(!img) delete img;
    if(!oriimg) delete oriimg;
}

// 打开图片按钮
void MainWindow::on_pushButton_openImg_clicked(){
    QString pic_filename = QFileDialog::getOpenFileName(this,tr("选择图片"),"D:",tr("图片文件（* png * jpg * bmp"));
    if(pic_filename == QString("")) return;
    std::cout<<"here-1\n"<<" "<<pic_filename.toStdString().c_str();
    if(img->load(pic_filename.toStdString().c_str())) enableButtons();;
}

// 接收图片已经转换的信号并切换为新图片
void MainWindow::changeImg(const char* src){
    img->Qimg.load(QString(src));
    changeImgStatus();
}

// 执行转换按钮
void MainWindow::on_pushButton_convert_clicked(){
    std::string choice = ui->comboBox_operation->currentText().toStdString();
    qDebug(choice.c_str());
    execPtr = img->execMap[choice];
    if(execPtr){
        (img->*execPtr)();
        return;
    }
    execPtrWithPara = img->execMapWithPara[choice];
    if(!execPtrWithPara) qDebug("get null func ptr");
    (img->*execPtrWithPara)(this, ui->lineEdit_factor->text().toInt());
}

// 更换显示的图片
void MainWindow::changeImgStatus(){
    if(ui->checkBox_sizeFixed->isChecked()) imgDisplay->setPixmap(img->Qimg.scaled(ui->scrollArea->size(), Qt::KeepAspectRatio));
    else imgDisplay->setPixmap(img->Qimg);
    imgDisplay->show();
}

// 更新原图信息
void MainWindow::newImg(){
    if(oriimg){
        delete oriimg;
        oriimg = nullptr;
    }
    std::cerr<<"newImg func here\n";
    oriimg = new PixMap(img);
}

// 撤回按钮
void MainWindow::on_pushButton_cancel_clicked(){
    // 指针指向的类的复制方法
    if(!oriimg){
        ui->statusBar->showMessage(QString("暂时无法撤回"), 3000);
        return ;
    }
    img->assign(oriimg);
    changeImgStatus();
}

// 另存为按钮
void MainWindow::on_pushButton_saveAs_clicked(){
    QString savefilename = QFileDialog::getSaveFileName(this,tr("保存图片"),"D:");
    if(!img->save(savefilename.toStdString().c_str())){
        ui->statusBar->showMessage(QString(tr("保存失败 ")), 5000);
    }
    ui->statusBar->showMessage(QString(tr("图片成功保存于 ")+savefilename), 5000);
}

// 拖入图片事件处理
void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    if(!event->mimeData()->urls()[0].fileName().right(3).compare("jpg")
            ||!event->mimeData()->urls()[0].fileName().right(3).compare("png")
            ||!event->mimeData()->urls()[0].fileName().right(3).compare("bmp")){
        event->acceptProposedAction();
    }
    else event->ignore();
}

// 放下图片事件处理
void MainWindow::dropEvent(QDropEvent *event){
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasUrls()){
        QList<QUrl>urlList = mimeData->urls();
        QString fileName = urlList.at(0).toLocalFile();
        if(!fileName.isEmpty()){
            qDebug()<<fileName;
            if(fileName.endsWith("jpg") || fileName.endsWith("png") || fileName.endsWith("bmp")){
                if(img->load(fileName.toStdString().c_str())){
                    ui->statusBar->showMessage(QString("成功打开 %1").arg(fileName), 5000);
                    enableButtons();
                }
                else ui->statusBar->showMessage(QString("打开失败"), 5000);
            }
            else ui->statusBar->showMessage(QString("打开失败"), 5000);
        }
    }
}

// 在GUI左下的消息栏发送通知
void MainWindow::log(const char * msg, int time){
    ui->statusBar->showMessage(QString(msg), time);
}
