
#include "chessboard.h"


chessBoard::chessBoard(qreal x, qreal y, qreal s, QGraphicsScene *parent) : QObject(parent),
    parentPtr(parent), state(action::select)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            board[i][j] = new chessBox(x + i*s, y + j*s, s, this);
            if(!((i+j)%2)) {
                board[i][j]->setBrush(Qt::white);
            }
            parentPtr->addItem(board[i][j]);
        }
    }
    rect = new QGraphicsRectItem(x-s*0.25, y-s*0.25, s*8.5, s*8.5);
    parentPtr->addItem(rect);

    for(int i = 0; i < 8; i++){
        text = new QGraphicsTextItem(QChar('a' + i));
        text->setPos(x + i*s + 0.5*s - text->boundingRect().width()/2, y + 8.125*s - text->boundingRect().height()/2);
        parentPtr->addItem(text);
    }

    for(int i = 0; i < 8; i++){
        text = new QGraphicsTextItem(QChar('1' + i));
        text->setPos(x - 0.125*s - text->boundingRect().width()/2, y + 7.5*s - i*s - text->boundingRect().height()/2);
        parentPtr->addItem(text);
    }
    drawPieces(pionek);
}

void chessBoard::drawPieces(piece *pionek)
{
    pionek = new pawn(team::white);
    pionek->setImage();
    board[0][1]->drawPiece(pionek);
    parentPtr->addItem(pionek);


}

action chessBoard::getState()
{
    return state;
}

void chessBoard::setState(action newState)
{
    state = newState;
}
