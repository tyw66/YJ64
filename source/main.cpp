#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include "database.h"


int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//中文转码声明
    QApplication a(argc, argv);

    //
    Database::inst()->read(":/data.txt");

    //
    MainWindow w;
    w.show();

    return a.exec();
}

