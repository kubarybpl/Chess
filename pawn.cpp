
#include "pawn.h"
#include "chessboard.h"
#include <QDebug>

pawn::pawn(chessEnum color, chessBoard *board) : piece(color,board)
{
}

void pawn::setImage()
{
    if(player == chessEnum::white) setPixmap(QPixmap(":/pieces/pawn1.png"));
    if(player == chessEnum::black) setPixmap(QPixmap(":/pieces/pawn.png"));
}

std::vector<std::vector<int>> pawn::getMoves()
{
    if(player == chessEnum::white)
    {
        if(row - 1 >= 0 && boardPtr->getBoxState(col,row - 1) == chessEnum::none)
        {
            avaliableMoves.push_back(std::vector<int>{col,row-1});

            if(boardPtr->getBoxState(col+1,row - 1) == chessEnum::black && col + 1 <= 7 ){
                avaliableMoves.push_back(std::vector<int>{col+1,row-1});
            }
            if(boardPtr->getBoxState(col-1,row - 1) == chessEnum::black && col - 1 <= 0){
                avaliableMoves.push_back(std::vector<int>{col-1,row-1});
            }

            if(moved == chessEnum::notMoved && row - 2 >= 0)
            {
                if(boardPtr->getBoxState(col,row - 2) == chessEnum::none){
                    avaliableMoves.push_back(std::vector<int>{col,row-2});
                }
                if(boardPtr->getBoxState(col+1,row - 2) == chessEnum::black && col + 1 <= 7 ){
                    avaliableMoves.push_back(std::vector<int>{col+1,row-2});
                }
                if(boardPtr->getBoxState(col-1,row - 2) == chessEnum::black && col - 1 <= 0){
                    avaliableMoves.push_back(std::vector<int>{col-1,row-2});
                }
            }

        }
    }
    return avaliableMoves;
}

