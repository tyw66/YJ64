#include "model.h"
#include "database.h"
#include <QDebug>

Diagram::Diagram(Diagram8 up, Diagram8 down)
{
    m_up = up;
    m_down = down;
}

QString Diagram::name()
{
   return Database::inst()->queryDiagramName(m_up,m_down);
}


void testDiagram()
{
    Database::inst()->read(":/data.txt");

    Diagram testGua(Gen,Kan);
    qDebug() << testGua.name();
}


