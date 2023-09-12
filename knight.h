
#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class knight : public piece
{
public:
    knight(chessEnum color = chessEnum::white, chessBoard *board = nullptr);
    virtual void setImage() override;
    virtual std::vector<myTemplate<int, chessEnum>> getMoves();
};

#endif // KNIGHT_H
