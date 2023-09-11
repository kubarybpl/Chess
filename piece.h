
#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include <vector>
#include "chessenum.h"

class chessBoard;
class piece : public QGraphicsPixmapItem
{
public:
    piece(chessEnum color, chessBoard *board = nullptr, QGraphicsItem *parent = nullptr);
    virtual void setImage() = 0;
    virtual std::vector<std::vector<int>> getMoves() = 0;
    void setXY(int x, int y);
    void clearMoves();
    void movedPiece();
    void killHim();
    chessEnum getType();
    chessEnum getTeam();
    chessEnum isMoved();
protected:
    QGraphicsItem *parent;
    std::vector<std::vector<int>> avaliableMoves;
    chessEnum player;
    chessBoard *boardPtr;
    chessEnum moved;
    chessEnum isAlive;
    chessEnum type;
    int row;
    int col;
};

#endif // PIECE_H
