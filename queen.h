
#ifndef QUEEN_H
#define QUEEN_H

#include <piece.h>
#include "chessboard.h"


class queen : public piece
{
public:
    queen(chessEnum color = chessEnum::white, chessBoard *board = nullptr);
    virtual void setImage();
    virtual std::vector<myTemplate<int, chessEnum>> getMoves();
};
#endif // QUEEN_H
