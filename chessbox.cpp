
#include "chessbox.h"


chessBox::chessBox(qreal x, qreal y, qreal s, chessBoard *object, QGraphicsItem *parent) : QGraphicsRectItem(x, y, s, s, parent),
    boxState(state::free), side(team::none), parentPtr(object)
{
    this->setBrush(Qt::black);
    pen = QPen(Qt::black);
    pen.setWidth(0);
    this->setPen(pen);

}

void chessBox::drawPiece(piece *element)
{
    QPointF center = this->boundingRect().center();
    element->setPos(center - QPointF(element->boundingRect().width()/2, element->boundingRect().height()/2));
    boxState = state::occupied;
    side = element->getTeam();
}


void chessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(parentPtr->getState() == action::select && boxState == state::free) setBrush(QBrush(Qt::blue));
    if(parentPtr->getState() == action::select && boxState == state::occupied)
    {
        setBrush(QBrush(Qt::red));
        parentPtr->setState(action::move);
    }
    if(parentPtr->getState() == action::move && boxState == state::free /* != czy jest do zbicia*/)
    {
        //release
        setBrush(QBrush(Qt::green));
        parentPtr->setState(action::select);
    }
    //if(parentPtr->getState() == action::select && boxState == state::occupied) setBrush(QBrush(Qt::red));
    //QGraphicsRectItem::mousePressEvent(event);

}

