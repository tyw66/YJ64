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


    //

//    ui->graphicsView->setLayout(ui->verticalLayout);

}

void MainWindow::initDiagrams()
{
    //初始化为乾卦
    m_diagram.change("0,0,0,1,1,1");
    ui->label_name->setText(m_diagram.name());
    ui->label_intro->setText(m_diagram.guaci());

    //从下到上画阳爻
    for(int i = 0; i < 6; i++){
        Yao* yao = m_diagram.getYao(i);
        if(yao){
            m_scene->addItem(yao);
        }
    }

    connect(&m_diagram,SIGNAL(diagramChanged()),
            this,SLOT(onDiagramChanged()));

}


void MainWindow::onDiagramChanged()
{
    ui->label_name->setText(m_diagram.name());
    ui->label_intro->setText(m_diagram.guaci());
}
