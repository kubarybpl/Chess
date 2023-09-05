
#ifndef PAWN_H
#define PAWN_H

#include <piece.h>


class pawn : public piece
{
public:
    pawn(team color = team::white);
    void setImage() override;
private:
    team player;
};

#endif // PAWN_H
