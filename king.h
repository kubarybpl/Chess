
#ifndef KING_H
#define KING_H

#include <piece.h>


class king : public piece
{
public:
    king(chessEnum color = chessEnum::white, chessBoard *board = nullptr);
    virtual void setImage();
    virtual std::vector<myTemplate<int, chessEnum>> getMoves();
};

#endif // KING_H
