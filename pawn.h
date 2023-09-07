
#ifndef PAWN_H
#define PAWN_H

#include <piece.h>

class pawn : public piece
{
public:
    pawn(chessEnum color = chessEnum::white, chessBoard *board = nullptr);
    virtual void setImage();
    virtual std::vector<std::vector<int>> getMoves();

private:

};

#endif // PAWN_H
