
#include "queen.h"

queen::queen(chessEnum color, chessBoard *board) : piece(color,board)
{
}

void queen::setImage()
{
    if(player == chessEnum::white) setPixmap(QPixmap(":/pieces/queen1.png"));
    if(player == chessEnum::black) setPixmap(QPixmap(":/pieces/queen.png"));
}

std::vector<std::vector<int>> queen::getMoves()
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
                avaliableMoves.push_back(std::vector<int>{col + i, row + j});
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

    // down
    x = 0;
    i = 0, j = -1;
    while(row + j >= 0 && !x)
    {
        checkAndPush(i, j);
        j--;
    }

    // up
    x = 0;
    i = 0, j = 1;
    while(row + j <= 7 && !x)
    {
        checkAndPush(i,j);
        j++;
    }

    // left
    x = 0;
    i = -1, j = 0;
    while(col + i >= 0 && !x)
    {
        checkAndPush(i, j);
        i--;
    }

    // right
    x = 0;
    i = 1, j = 0;
    while(col + i <= 7 && !x)
    {
        checkAndPush(i,j);
        i++;
    }

    return avaliableMoves;
}
