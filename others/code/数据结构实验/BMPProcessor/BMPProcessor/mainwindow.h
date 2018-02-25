#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<pixmap.h>
#include<QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void init();
    ~MainWindow();
    PixMap* img;
    PixMap* oriimg;
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
signals:
    //void toGrey24
private slots:
    void on_pushButton_openImg_clicked();
    void changeImg(const char *src);
    void on_pushButton_convert_clicked();
    void changeImgStatus();
    void on_pushButton_cancel_clicked();
    void newImg();
    // void mergeOriginalImg();
    void on_pushButton_saveAs_clicked();
    void log(const char*, int time);
private:
    void initStyle();
    void disableButtons();
    void enableButtons();
    void addOperations();
    void addConncetions();

    Ui::MainWindow *ui;
    QLabel* imgDisplay;
    bool (PixMap::*execPtr)();
    bool (PixMap::*execPtrWithPara)(QWidget*, int);
};

#endif // MAINWINDOW_H
