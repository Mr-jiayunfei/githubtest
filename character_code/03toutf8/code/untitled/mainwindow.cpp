#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QString  str1 = QString::fromUtf8(u8"你好世界");
    QString test = "你好，世界";
    std::string str =test.toUtf8().toStdString();

    QByteArray encodedString = "你好";
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
     QString string = codec->toUnicode(encodedString);

//    QString string = "...";
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QByteArray encodedString = codec->fromUnicode(string);
}

MainWindow::~MainWindow()
{
    delete ui;
}
