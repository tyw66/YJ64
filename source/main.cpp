#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include "model.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//中文转码声明

    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    testDiagram();
//    return a.exec();
}

