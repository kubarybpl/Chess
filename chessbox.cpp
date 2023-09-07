
#include "chessbox.h"
#include <QDebug>

piece *chessBox::killerPiece = nullptr;
chessBox *chessBox::previousBox= nullptr;

chessBox::chessBox(qreal x, qreal y, qreal s, int col, int row, chessBoard *object, QGraphicsItem *parent) : QGraphicsRectItem(x, y, s, s, parent),
    boxState(chessEnum::none), boardPtr(object), row(row), col(col)
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

void chessBox::movePiece()
{
    previousBox->boxState = chessEnum::none;
    previousBox->currentPiece = nullptr;
    previousBox = nullptr;
    drawPiece(killerPiece);
    killerPiece->clearMoves();
    killerPiece->movedPiece();
    killerPiece = nullptr;
    boardPtr->setState(chessEnum::select);
    boardPtr->resetColors();
}


chessEnum chessBox::getBoxState()
{
    return boxState;
}

QBrush chessBox::getColor()
{
    return color;
}

void chessBox::setColor(QBrush brush)
{
    color = brush;
    this->setBrush(color);
}


void chessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Chosing piece to move
    if(boardPtr->getState() == chessEnum::select && boxState != chessEnum::none)
    {
        if(boxState == boardPtr->getTurn())
        {
            if(boxState != chessEnum::none) qDebug() << "costam";
            boardPtr->showMoves(currentPiece->getMoves());
            setBrush(QBrush(Qt::red));
            boardPtr->setState(chessEnum::move);
            killerPiece = currentPiece;
            previousBox = this;
        }
    }
    // If chosen piece, but resigning from move
    if(boardPtr->getState() == chessEnum::move && boxState == chessEnum::none && color != Qt::yellow )
    {
        boardPtr->resetColors();
        boardPtr->setState(chessEnum::select);
        killerPiece->clearMoves();
        killerPiece = nullptr;
    }
    // Kill me
    if(boardPtr->getState() == chessEnum::move && boxState != chessEnum::none && color == Qt::yellow )
    {
        boardPtr->removePiece(currentPiece);
        movePiece();
    }
    // Move
    if(boardPtr->getState() == chessEnum::move && boxState == chessEnum::none && color == Qt::yellow )
    {
        movePiece();
    }

}

