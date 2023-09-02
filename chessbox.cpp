
#include "chessbox.h"


chessBox::chessBox(qreal x, qreal y, qreal s, QGraphicsItem *parent) : QGraphicsRectItem(x, y, s, s, parent)
{
    this->setBrush(Qt::black);
}

void chessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    setBrush(QBrush(Qt::red));
    QGraphicsRectItem::mousePressEvent(event);

}
