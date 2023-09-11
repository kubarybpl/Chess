
#include "piece.h"

piece::piece(chessEnum color,chessBoard *board, QGraphicsItem *parent) : QGraphicsPixmapItem(), player(color),
    row(0), col(0), boardPtr(board), moved(chessEnum::notMoved), isAlive(chessEnum::alive), type(chessEnum::none)
{
}

chessEnum piece::getTeam()
{
    return player;
}

void piece::setXY(int x, int y)
{
    row = y;
    col = x;
}

void piece::clearMoves()
{
    avaliableMoves.clear();
}

void piece::movedPiece()
{
    moved = chessEnum::moved;
}

void piece::killHim()
{
    isAlive = chessEnum::dead;
}

chessEnum piece::getType()
{
    return type;
}

chessEnum piece::isMoved()
{
    return moved;
}
