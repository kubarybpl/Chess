
#ifndef ROOK_H
#define ROOK_H

#include <piece.h>
#include "chessboard.h"


class rook : public piece
{
public:
    rook(chessEnum color = chessEnum::white, chessBoard *board = nullptr);
    virtual void setImage();
    virtual std::vector<myTemplate<int, chessEnum>> getMoves();
};

#endif // ROOK_H
