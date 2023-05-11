#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
  ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initDiagrams();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initUI()
{
    //初始化背景与场景
    m_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/basic/bg.jpg"));
    borderPen.setStyle(Qt::NoPen);

    ui->label_name->setStyleSheet("color:#bbb;");

    //界面布局
    QGraphicsLinearLayout *interLayout = new QGraphicsLinearLayout;
//    interLayout->addLayout(ui->layout_name);
//    interLayout->addStretch();
//    interLayout->addLayout(ui->layout_info);
//    ui->graphicsView->setLayout(interLayout);

    QGraphicsProxyWidget *labelProxy = m_scene->addWidget(ui->label_name);
    QGraphicsWidget * gWidget = new QGraphicsWidget();
    interLayout->addItem((QGraphicsWidget *)labelProxy);//qt4不需要强转，qt5必须强转
    gWidget->setLayout(interLayout);
    m_scene->addItem(gWidget);
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
    connect(&m_diagram,SIGNAL(yaoHoverd(int)),
            this,SLOT(onShowYaoci(int)));
}


void MainWindow::onDiagramChanged()
{
    ui->label_name->setText(m_diagram.name());
    ui->label_intro->setText(m_diagram.guaci());
}

void MainWindow::onShowYaoci(int index)
{
    ui->label_yaoci->setText(m_diagram.yaoci(index));
}


