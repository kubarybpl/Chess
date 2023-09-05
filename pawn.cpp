
#include "pawn.h"

pawn::pawn(team color) : piece(color), player(color)
{
}

void pawn::setImage()
{
    if(player == team::white) setPixmap(QPixmap(":/pieces/pawn1.png"));
    if(player == team::black) setPixmap(QPixmap(":/pieces/pawn.png"));
}

