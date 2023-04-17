#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "graphicsitemyao.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
  ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initBackground();
    initDiagrams();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initBackground()
{
    //初始化背景与场景
    m_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/basic/bg.jpg"));
    borderPen.setStyle(Qt::NoPen);
}

void MainWindow::initDiagrams()
{
    //初始化为乾卦
    ui->label_name->setText(tr("QianGua"));

    //从下到上画阳爻
    GraphicsItemYao *line1 = new GraphicsItemYao(-200,130);
    m_scene->addItem(line1);

    GraphicsItemYao *line2 = new GraphicsItemYao(-200,70);
    m_scene->addItem(line2);

    GraphicsItemYao *line3 = new GraphicsItemYao(-200,10);
    m_scene->addItem(line3);

    GraphicsItemYao *line4 = new GraphicsItemYao(-200,-50);
    m_scene->addItem(line4);

    GraphicsItemYao *line5 = new GraphicsItemYao(-200,-110);
    m_scene->addItem(line5);

    GraphicsItemYao *line6 = new GraphicsItemYao(-200,-170);
    m_scene->addItem(line6);

}
