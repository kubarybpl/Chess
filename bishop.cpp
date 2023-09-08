
#include "bishop.h"

bishop::bishop(chessEnum color, chessBoard *board) : piece(color,board)
{
}

void bishop::setImage()
{
    if(player == chessEnum::white) setPixmap(QPixmap(":/pieces/bishop1.png"));
    if(player == chessEnum::black) setPixmap(QPixmap(":/pieces/bishop.png"));
}

std::vector<std::vector<int>> bishop::getMoves()
{
    chessEnum cSide;
    if(player == chessEnum::black)  cSide = chessEnum::white;
    else    cSide = chessEnum::black;

    int x = 0;
    // down-right
    for(int i = col + 1, j = row + 1; i <= 7 && j <= 7 && !x; i++,j++)
    //while(int i = col + 1, j = row + 1; i <= 7 && j <= 7; i++,j++)
    {
        if(boardPtr->getBoxState(i, j) == player)   x++;
        else if(boardPtr->getBoxState(i, j) == cSide)
        {
            x++;
            avaliableMoves.push_back(std::vector<int>{i, j});
        }
        else if(boardPtr->getBoxState(i, j) == chessEnum::none)
            avaliableMoves.push_back(std::vector<int>{i, j});
    }

    x = 0;
    // down-left
    for(int i = col - 1, j = row + 1; i >= 0 && j <= 7 && !x; i--,j++)
    {
        if(boardPtr->getBoxState(i, j) == player)   x++;
        else if(boardPtr->getBoxState(i, j) == cSide)
        {
            x++;
            avaliableMoves.push_back(std::vector<int>{i, j});

        }
        else if(boardPtr->getBoxState(i, j) == chessEnum::none)
            avaliableMoves.push_back(std::vector<int>{i, j});
    }

    x = 0;
    // up-right
    for(int i = col + 1, j = row - 1; i <= 7 && j >= 0 && !x; i++,j--)
    {
        if(boardPtr->getBoxState(i, j) == player)   x++;
        else if(boardPtr->getBoxState(i, j) == cSide)
        {
            x++;
            avaliableMoves.push_back(std::vector<int>{i, j});
        }
        else if(boardPtr->getBoxState(i, j) == chessEnum::none)
            avaliableMoves.push_back(std::vector<int>{i, j});
    }

    x = 0;
    // up-left
    for(int i = col - 1, j = row - 1; i >= 0 && j >= 0 && !x; i--,j--)
    {
        if(boardPtr->getBoxState(i, j) == player) x++;
        else if(boardPtr->getBoxState(i, j) == cSide)
        {
            x++;
            avaliableMoves.push_back(std::vector<int>{i, j});
        }
        else if(boardPtr->getBoxState(i, j) == chessEnum::none)
            avaliableMoves.push_back(std::vector<int>{i, j});
    }
    return avaliableMoves;
}

