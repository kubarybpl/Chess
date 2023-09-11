
#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>
#include "chessboard.h"


class bishop : public piece
{
public:
    bishop(chessEnum color = chessEnum::white, chessBoard *board = nullptr);
    virtual void setImage();
    virtual std::vector<std::vector<int>> getMoves();
};

#endif // BISHOP_H
