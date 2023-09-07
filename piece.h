
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
    void returnColor();
    void drawPiece();
    chessEnum getTeam();
    void setXY(int x, int y);
    void clearMoves();
    void movedPiece();
    virtual void setImage() = 0;
    virtual std::vector<std::vector<int>> getMoves() = 0;
protected:
    QGraphicsItem *parent;
    std::vector<std::vector<int>> avaliableMoves;
    chessEnum player;
    chessBoard *boardPtr;
    chessEnum moved;
    int row;
    int col;
};

#endif // PIECE_H
