
#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include <vector>
#include "chessenum.h"
#include "templateMoves.h"

class chessBoard;
class piece : public QGraphicsPixmapItem
{
public:
    piece(chessEnum color, chessBoard *board = nullptr, QGraphicsItem *parent = nullptr);
    virtual void setImage() = 0;
    virtual std::vector<myTemplate<int,chessEnum>> getMoves() = 0;
    void setXY(int x, int y);
    void clearMoves();
    void movedPiece();
    void killHim();
    chessEnum Alive();
    chessEnum getType();
    chessEnum getTeam();
    chessEnum isMoved();
protected:
    QGraphicsItem *parent;
    std::vector<myTemplate<int,chessEnum>> avaliableMoves;
    chessEnum player;
    chessBoard *boardPtr;
    chessEnum moved;
    chessEnum isAlive;
    chessEnum type;
    int row;
    int col;
};

#endif // PIECE_H
