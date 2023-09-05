
#include "piece.h"



piece::piece(team color) : QGraphicsPixmapItem(), player(color)
{

}

void piece::returnColor()
{

}

void piece::drawPiece()
{

}

team piece::getTeam()
{
    return player;
}
