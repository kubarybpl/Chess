
#include "chessboard.h"


chessBoard::chessBoard(qreal x, qreal y, QGraphicsScene *parent) : QObject()
{
    board.resize(8);
    for(int i = 0; i < 8; i++){
        board[i].resize(8);
        for(int j = 0; j < 8; j++) {
            board[i][j] = new chessBox(x + i*50, y + j*50);
            if(!((i+j)%2)) board[i][j]->setBrush(Qt::white);
            parent->addItem(board[i][j]);
        }
    }
}

