#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "diagram.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onDiagramChanged();

private:
    void initBackground();
    void initDiagrams();


private:
    Ui::MainWindow *ui;
    QGraphicsScene* m_scene;
    QPen borderPen;

    Diagram m_diagram;

};
#endif // MAINWINDOW_H
