#ifndef GRAPHICSITEMYAO_H
#define GRAPHICSITEMYAO_H
#include <QGraphicsItem>

class GraphicsItemYao : public QGraphicsItem
{
public:
    GraphicsItemYao(int x, int y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;

private:
    QColor m_color;
    bool m_broken;
};

#endif // GRAPHICSITEMYAO_H
