
#include "king.h"
#include "chessboard.h"

king::king(chessEnum color, chessBoard *board) : piece(color,board)
{
    type = chessEnum::king;
}

void king::setImage()
{
    if(player == chessEnum::white) setPixmap(QPixmap(":/pieces/king1.png"));
    if(player == chessEnum::black) setPixmap(QPixmap(":/pieces/king.png"));
}

std::vector<myTemplate<int, chessEnum>> king::getMoves()
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


    checkAndPush(0, 1);
    checkAndPush(0, -1);
    checkAndPush(1, 1);
    checkAndPush(1, -1);
    checkAndPush(1, 0);
    checkAndPush(-1, -1);
    checkAndPush(-1, 1);
    checkAndPush(-1, 0);

    return avaliableMoves1;
}
