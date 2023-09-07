
#include "chessboard.h"
#include <QDebug>

chessBoard::chessBoard(qreal x, qreal y, qreal s, QGraphicsScene *parent) : QObject(parent),
    parentPtr(parent), state(chessEnum::select), turn(chessEnum::white)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            board[i][j] = new chessBox(x + i*s, y + j*s, s,i , j,  this);
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
    pionek = new pawn(chessEnum::white,this);
    pionek->setImage();
    board[1][6]->drawPiece(pionek);

    pawn *pionek1 = new pawn(chessEnum::black);
    pionek1->setImage();
    board[2][4]->drawPiece(pionek1);


}

chessEnum chessBoard::getState()
{
    return state;
}

chessEnum chessBoard::getBoxState(int x, int y)
{
    return board[x][y]->getBoxState();
}

void chessBoard::resetColors()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            if(!((i+j)%2)) board[i][j]->setColor(Qt::white);
            else board[i][j]->setColor(Qt::gray);
        }
    }
}

void chessBoard::addPiece(piece *element)
{
    if(element->scene() == nullptr) parentPtr->addItem(element);
}

void chessBoard::removePiece(piece *element)
{
    parentPtr->removeItem(element);
}

void chessBoard::setState(chessEnum newState)
{
    state = newState;
}

chessEnum chessBoard::getTurn()
{
    return turn;
}

void chessBoard::showMoves(std::vector<std::vector<int> > moves)
{
    for(auto m : moves)
    {
        qDebug() << m[0];
        qDebug() << m[1];
        board[m[0]][m[1]]->setColor(Qt::yellow);
    }
}
