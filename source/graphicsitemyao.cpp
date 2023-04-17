#include "graphicsitemyao.h"
#include <QDebug>
#include <QPainter>
#include <QStyle>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>

GraphicsItemYao::GraphicsItemYao(int x, int y)
{
    setPos(x,y);
    setZValue((x + y) % 2);
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);

    m_color = QColor("#333");
    m_broken = false;
}

QRectF GraphicsItemYao::boundingRect() const
{
    return QRect(0,0,400,40);
}

void GraphicsItemYao::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    QColor fillColor = m_color;
    if (option->state & QStyle::State_MouseOver){
        fillColor = QColor("#c78c64");
    }

    //阴爻
    if(m_broken){
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(fillColor));
        painter->drawRect(0,0,190,40);
        painter->drawRect(210,0,190,40);
    }
    //阳爻
    else{
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(fillColor));
        painter->drawRect(0,0,400,40);
    }
}


void GraphicsItemYao::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_broken = !m_broken;
    QGraphicsItem::mousePressEvent(event);
    update();
}
