
#include "knight.h"
#include "chessboard.h"

knight::knight(chessEnum color, chessBoard *board) : piece(color,board)
{
}

void knight::setImage()
{
    if(player == chessEnum::white) setPixmap(QPixmap(":/pieces/horse1.png"));
    if(player == chessEnum::black) setPixmap(QPixmap(":/pieces/horse.png"));
}

std::vector<myTemplate<int, chessEnum>> knight::getMoves()
{
    chessEnum cSide;
    if(player == chessEnum::black) cSide = chessEnum::white;
    else cSide = chessEnum::black;

    auto checkAndPush = [&](int i, int j)
    {
        if (col + i <= 7 && row + j >= 0 && col + i >= 0 && row + j <= 7)
        {
            if (boardPtr->getBoxState(col + i, row + j) == chessEnum::none || boardPtr->getBoxState(col + i, row + j) == cSide)
            {
                avaliableMoves.push_back(std::vector<int>{col + i, row + j});
                avaliableMoves1.push_back(myTemplate(col + i, row + j, chessEnum::none));
            }
        }
    };

    checkAndPush(1, -2);
    checkAndPush(1, 2);
    checkAndPush(-1, -2);
    checkAndPush(-1, 2);
    checkAndPush(2, -1);
    checkAndPush(2, 1);
    checkAndPush(-2, -1);
    checkAndPush(-2, 1);

    return avaliableMoves1;
}

