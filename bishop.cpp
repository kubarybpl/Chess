
#include "bishop.h"

bishop::bishop(chessEnum color, chessBoard *board) : piece(color,board)
{
}

void bishop::setImage()
{
    if(player == chessEnum::white) setPixmap(QPixmap(":/pieces/bishop1.png"));
    if(player == chessEnum::black) setPixmap(QPixmap(":/pieces/bishop.png"));
}

std::vector<myTemplate<int, chessEnum>> bishop::getMoves()
{
    chessEnum cSide;
    if(player == chessEnum::black)  cSide = chessEnum::white;
    else    cSide = chessEnum::black;

    int x, j, i;
    auto checkAndPush = [&](int i, int j)
    {
        if (col + i <= 7 && row + j >= 0 && col + i >= 0 && row + j <= 7)
        {
            if(boardPtr->getBoxState(col + i, row + j) == player) x++;
            else if (boardPtr->getBoxState(col + i, row + j) == chessEnum::none || boardPtr->getBoxState(col + i, row + j) == cSide)
            {
                avaliableMoves.push_back(std::vector<int>{col + i, row + j});
                avaliableMoves1.push_back(myTemplate(col + i, row + j, chessEnum::none));
            }
            if(boardPtr->getBoxState(col + i, row + j) == cSide) x++;
        }
    };

    // down-right
    x = 0;
    i = 1, j = 1;
    while(col + i >= 0 && row + j <= 7 && !x)
    {
        checkAndPush(i, j);
        i++;
        j++;
    }

    // down-left
    x = 0;
    i = -1, j = 1;
    while(col + i >= 0 &&  row + j <= 7 && !x)
    {
        checkAndPush(i, j);
        i--;
        j++;
    }

    // up-right
    x = 0;
    i = 1, j = -1;
    while(col + i <= 7 && row + j >= 0 && !x)
    {
        checkAndPush(i,j);
        i++;
        j--;
    }

    // up-left
    x = 0;
    i = -1, j = -1;
    while(col + i >= 0 && row + j >= 0 && !x)
    {
        checkAndPush(i,j);
        i--;
        j--;
    }

    return avaliableMoves1;
}

