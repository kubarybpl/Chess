
#include "pawn.h"
#include "chessboard.h"
#include <QDebug>

pawn::pawn(chessEnum color, chessBoard *board) : piece(color,board)
{
    type = chessEnum::pawn;
}

void pawn::setImage()
{
    if(player == chessEnum::white) setPixmap(QPixmap(":/pieces/pawn1.png"));
    if(player == chessEnum::black) setPixmap(QPixmap(":/pieces/pawn.png"));
}

std::vector<myTemplate<int, chessEnum>> pawn::getMoves()
{
    chessEnum cSide;
    if(player == chessEnum::black) cSide = chessEnum::white;
    else cSide = chessEnum::black;

    auto checkAndPush = [&](int i, int j)
    {
        if (col + i <= 7 && row + j >= 0 && col + i >= 0 && row + j <= 7)
        {
            if (boardPtr->getBoxState(col + i, row + j) == chessEnum::none)
            {
                avaliableMoves.push_back(std::vector<int>{col + i, row + j});
                avaliableMoves1.push_back(myTemplate(col + i, row + j, chessEnum::none));
            }
        }
    };

    auto checkAndAttack = [&](int i, int j) {
        if (col + i <= 7 && row + j >= 0 && col + i >= 0 && row + j <= 7)
        {
            if (boardPtr->getBoxState(col + i, row + j) == cSide)
            {
                avaliableMoves.push_back(std::vector<int>{col + i, row + j});
                avaliableMoves1.push_back(myTemplate(col + i, row + j, chessEnum::none));
            }
        }
    };

    if(player == chessEnum::white)
    {
        checkAndPush(0,- 1);
        checkAndAttack(-1, -1);
        checkAndAttack(1, -1);
        if(moved == chessEnum::notMoved && boardPtr->getBoxState(col,row - 1) == chessEnum::none)
        {
            checkAndPush(0,-2);
            avaliableMoves1.back().setPassant = chessEnum::passan;
        }
    }

    if(player == chessEnum::black)
    {
        checkAndPush(0, 1);
        checkAndAttack(-1, 1);
        checkAndAttack(1, 1);
        if(moved == chessEnum::notMoved && boardPtr->getBoxState(col,row + 1) == chessEnum::none)
        {
            checkAndPush(0, 2);
            avaliableMoves1.back().setPassant = chessEnum::passan;
        }
    }

    return avaliableMoves1;
}

