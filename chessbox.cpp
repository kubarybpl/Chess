
#include "chessbox.h"
#include <QDebug>


chessBox::chessBox(qreal x, qreal y, qreal s, int col, int row, chessBoard *object, QGraphicsItem *parent) : QGraphicsRectItem(x, y, s, s, parent),
    boxState(chessEnum::none), boardPtr(object), row(row), col(col), flag(chessEnum::none)
{
    if(!((row+col)%2))  color = Qt::white;
    else color = Qt::gray;

    this->setBrush(color);
    pen = QPen(Qt::black);
    pen.setWidth(0);
    this->setPen(pen);

}

void chessBox::drawPiece(piece *element)
{
    // setting piece
    currentPiece = element;
    element->setXY(col,row);
    //drawing piece
    QPointF center = this->boundingRect().center();
    element->setPos(center - QPointF(element->boundingRect().width()/2, element->boundingRect().height()/2));
    boardPtr->addPiece(element);
    // setting box occupation
    boxState = element->getTeam();

}

chessEnum chessBox::getBoxState()
{
    return boxState;
}

QBrush chessBox::getColor()
{
    return color;
}

piece *chessBox::getPiece()
{
    return currentPiece;
}

void chessBox::setBoxState(chessEnum state)
{
    boxState = state;
}

void chessBox::setColor(QBrush brush)
{
    color = brush; // ???
    this->setBrush(color);
}

void chessBox::setPiece(piece *element)
{
    currentPiece = element;
}

void chessBox::setFlag(chessEnum data)
{
    flag = data;
}


void chessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // If piece is chosen, but resigning from move
    if(boardPtr->getState() == chessEnum::move && color != Qt::yellow && (boxState == chessEnum::none || boxState == boardPtr->giveKiller()->getTeam()))
    {
        boardPtr->resetColors();
        boardPtr->setState(chessEnum::select);
        boardPtr->giveKiller()->clearMoves();
        boardPtr->setKiller(nullptr);
    }
    // Chosing piece to move
    else if(boardPtr->getState() == chessEnum::select && boxState != chessEnum::none)
    {
        if(boxState == boardPtr->getTurn())
        {
            setBrush(QBrush(Qt::red));
            boardPtr->setState(chessEnum::move);
            boardPtr->setKiller(currentPiece);
            boardPtr->setPrevBox(this);
            boardPtr->showMoves(currentPiece->getMoves());
        }
    }
    // Kill me
    else if(boardPtr->getState() == chessEnum::move && boxState != chessEnum::none && color == Qt::yellow && flag != chessEnum::castling)
    {
        boardPtr->removePiece(currentPiece);
        boardPtr->movePiece(col, row);
    }
    // Move
    else if(boardPtr->getState() == chessEnum::move && boxState == chessEnum::none && color == Qt::yellow && flag != chessEnum::castling)
    {
        boardPtr->movePiece(col, row);
    }
    // Castling
    else if(boardPtr->getState() == chessEnum::move && flag == chessEnum::castling)
    {
        boardPtr->castling(col, row);
    }
}

