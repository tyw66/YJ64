#ifndef GRAPHICSITEMYAO_H
#define GRAPHICSITEMYAO_H
#include <QGraphicsItem>

class Yao : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Yao(int x, int y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setBroken(bool broken);

    int getIndex() const;
    void setIndex(int index);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;

signals:
    void yaoChanged(int,bool);


private:
    QColor m_color;
    bool m_broken;
    int m_index;

};

#endif // GRAPHICSITEMYAO_H
