#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


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
    m_diagram.change("0,0,0,1,1,1");
    ui->label_name->setText(m_diagram.name());

    //从下到上画阳爻
    for(int i = 0; i < 6; i++){
        Yao* yao = m_diagram.getYao(i);
        if(yao){
            m_scene->addItem(yao);
        }
    }

    connect(&m_diagram,SIGNAL(diagramChanged()),
            this,SLOT(onDiagramChanged()));

/*
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
*/

}


void MainWindow::onDiagramChanged()
{
    ui->label_name->setText(m_diagram.name());
}
