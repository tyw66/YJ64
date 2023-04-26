#include "yao.h"
#include <QDebug>
#include <QPainter>
#include <QStyle>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>

Yao::Yao(int x, int y)
{
    setPos(x,y);
    setZValue((x + y) % 2);
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);

    m_color = QColor("#333");
    m_broken = false;
    m_index = -1;
}

QRectF Yao::boundingRect() const
{
    return QRect(0,0,400,40);
}

void Yao::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void Yao::setBroken(bool broken)
{
    m_broken = broken;
    update();
}


void Yao::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    bool newStatus = !m_broken;
    setBroken(newStatus);
    QGraphicsItem::mousePressEvent(event);

    emit yaoChanged(m_index, newStatus);
}

int Yao::getIndex() const
{
    return m_index;
}

void Yao::setIndex(int index)
{
    m_index = index;
}
