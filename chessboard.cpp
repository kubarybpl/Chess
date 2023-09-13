
#include "chessboard.h"
#include "gamescene.h"
#include <QDebug>

piece *chessBoard::killerPiece = nullptr;
chessBox *chessBoard::previousBox= nullptr;

chessBoard::chessBoard(qreal x, qreal y, qreal s, gameScene *parent) : QObject(parent),
    parentPtr(parent), state(chessEnum::select), turn(chessEnum::white), specialMove(chessEnum::none)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = new chessBox(x + i*s, y + j*s, s, i, j,  this);
            parentPtr->addItem(board[i][j]);
        }
    }
    rect = new QGraphicsRectItem(x-s*0.25, y-s*0.25, s*8.5, s*8.5);
    parentPtr->addItem(rect);

    for(int i = 0; i < 8; i++)
    {
        text = new QGraphicsTextItem(QChar('a' + i));
        text->setPos(x + i*s + 0.5*s - text->boundingRect().width()/2, y + 8.125*s - text->boundingRect().height()/2);
        parentPtr->addItem(text);
    }

    for(int i = 0; i < 8; i++)
    {
        text = new QGraphicsTextItem(QChar('1' + i));
        text->setPos(x - 0.125*s - text->boundingRect().width()/2, y + 7.5*s - i*s - text->boundingRect().height()/2);
        parentPtr->addItem(text);
    }

    drawPieces();
}

void chessBoard::drawPieces()
{
    piecesWhite.reserve(16);
    piecesWhite.push_back(new rook(chessEnum::white,this));
    piecesWhite.push_back(new knight(chessEnum::white,this));
    piecesWhite.push_back(new bishop(chessEnum::white,this));
    piecesWhite.push_back(new queen(chessEnum::white,this));
    piecesWhite.push_back(new king(chessEnum::white,this));
    piecesWhite.push_back(new bishop(chessEnum::white,this));
    piecesWhite.push_back(new knight(chessEnum::white,this));
    piecesWhite.push_back(new rook(chessEnum::white,this));

    for(int i = 0; i <= 7; i++)
    {
        piecesWhite.push_back(new pawn(chessEnum::white,this));
        piecesWhite[i]->setImage();
        board[i][7]->drawPiece(piecesWhite[i]);
        piecesWhite[i + 8]->setImage();
        board[i][6]->drawPiece(piecesWhite[i + 8]);
    }

    piecesBlack.reserve(16);
    piecesBlack.push_back(new rook(chessEnum::black,this));
    piecesBlack.push_back(new knight(chessEnum::black,this));
    piecesBlack.push_back(new bishop(chessEnum::black,this));
    piecesBlack.push_back(new queen(chessEnum::black,this));
    piecesBlack.push_back(new king(chessEnum::black,this));
    piecesBlack.push_back(new bishop(chessEnum::black,this));
    piecesBlack.push_back(new knight(chessEnum::black,this));
    piecesBlack.push_back(new rook(chessEnum::black,this));

    for(int i = 0; i <= 7; i++)
    {
        piecesBlack.push_back(new pawn(chessEnum::black,this));
        piecesBlack[i]->setImage();
        board[i][0]->drawPiece(piecesBlack[i]);
        piecesBlack[i + 8]->setImage();
        board[i][1]->drawPiece(piecesBlack[i + 8]);
    }

}

chessEnum chessBoard::getState()
{
    return state;
}

chessEnum chessBoard::getBoxState(int x, int y)
{
    return board[x][y]->getBoxState();
}

void chessBoard::resetColors()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            if(!((i+j)%2)) board[i][j]->setColor(Qt::white);
            else board[i][j]->setColor(Qt::gray);
            board[i][j]->setFlag(chessEnum::none);
        }
    }
}

void chessBoard::addPiece(piece *element)
{
    if(element->scene() == nullptr) parentPtr->addItem(element);
}

void chessBoard::movePiece(int X, int Y)
{
    previousBox->setBoxState(chessEnum::none);
    previousBox->setPiece(nullptr);
    board[X][Y]->drawPiece(killerPiece);
    killerPiece->clearMoves();
    killerPiece->movedPiece();
    previousBox = nullptr;
    killerPiece = nullptr;
    setState(chessEnum::select);
    checkForCheck();
    resetColors();
    changeTurn();
}

void chessBoard::removePiece(piece *element)
{
    element->killHim();
    parentPtr->removeItem(element);
}

void chessBoard::setState(chessEnum newState)
{
    state = newState;
}

chessEnum chessBoard::getTurn()
{
    return turn;
}

void chessBoard::changeTurn()
{
    if(turn == chessEnum::white)
    {
        turn = chessEnum::black;
        parentPtr->changeTurn(chessEnum::black);
    }
    else
    {
        turn = chessEnum::white;
        parentPtr->changeTurn(chessEnum::white);
    }
}

void chessBoard::setKiller(piece *element)
{
    killerPiece = element;
}

void chessBoard::setPrevBox(chessBox *box)
{
    previousBox = box;
}

void chessBoard::castling(int X, int Y)
{
    // White right
    if(X == 7 && Y == 7)
    {
        movePiece(6,7);
        killerPiece = board[7][7]->getPiece();
        previousBox = board[7][7];
        movePiece(5,7);
        changeTurn();
    }
    // White left
    if(X == 0 && Y == 7)
    {
        movePiece(2,7);
        killerPiece = board[0][7]->getPiece();
        previousBox = board[0][7];
        movePiece(3,7);
        changeTurn();
    }
    // Black right
    if(X == 7 && Y == 0)
    {
        movePiece(6,0);
        killerPiece = board[7][0]->getPiece();
        previousBox = board[7][0];
        movePiece(5,0);
        changeTurn();
    }
    // Black left
    if(X == 0 && Y == 0)
    {
        movePiece(2,0);
        killerPiece = board[0][0]->getPiece();
        previousBox = board[0][0];
        movePiece(3,0);
        changeTurn();
    }
}

void chessBoard::setPassant(int X, int Y)
{
    movePiece(X,Y);
    if(turn == chessEnum::black)
    {
        board[X][Y + 1]->setFlag(chessEnum::passan);
    }
    if(turn == chessEnum::white)
    {
        board[X][Y - 1]->setFlag(chessEnum::passan);
    }
}

void chessBoard::passant(int X, int Y)
{
    if(killerPiece->getType() == chessEnum::pawn)
    {
        if(turn == chessEnum::white)
        {
            removePiece(board[X][Y + 1]->getPiece());
            movePiece(X,Y);
        }
        else if(turn == chessEnum::black)
        {
            removePiece(board[X][Y - 1]->getPiece());
            movePiece(X,Y);
        }
    }
    else movePiece(X,Y);
}

void chessBoard::checkForCheck()
{
    setCheck(chessEnum::none);
    static int wCheck = 0;
    static int bCheck = 0;
    int x = 0;
    // Check for white king
    for(auto wB : piecesBlack)
    {
        if(wB->Alive() == chessEnum::alive)
        {
            auto moves = wB->getMoves();
            for(auto m : moves)
            {
                if(board[m.x][m.y]->getBoxState() == chessEnum::white && board[m.x][m.y]->getPiece()->getType() == chessEnum::king)
                {
                    x++;
                }
            }
        }
    }
    if(!x) wCheck = 0;
    else wCheck++;
    if(wCheck == 2) gameOver(chessEnum::white);
    if(wCheck == 1) setCheck(chessEnum::white);

    x = 0;
    for(auto wB : piecesWhite)
    {
        if(wB->Alive() == chessEnum::alive)
        {
            auto moves = wB->getMoves();
            for(auto m : moves)
            {
                if(board[m.x][m.y]->getBoxState() == chessEnum::black && board[m.x][m.y]->getPiece()->getType() == chessEnum::king)
                {
                    x++;
                }
            }
        }
    }
    if(!x) bCheck = 0;
    else bCheck++;
    if(bCheck == 2) gameOver(chessEnum::black);
    if(bCheck == 1) setCheck(chessEnum::black);

}

void chessBoard::setCheck(chessEnum player)
{
    parentPtr->setState(player);
}

void chessBoard::gameOver(chessEnum player)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            board[i][j]->disableClick();
        }
    }
    parentPtr->gameOver(player);
}

piece *chessBoard::giveKiller()
{
    return killerPiece;
}

chessBox *chessBoard::givePrevBox()
{
    return previousBox;
}

void chessBoard::showMoves(std::vector<myTemplate<int, chessEnum> > moves)
{
    if(killerPiece->getType() != chessEnum::king)
    {
        for(auto m : moves)
        {
            board[m.x][m.y]->setColor(Qt::yellow);

            if(m.setPassant == chessEnum::passan)
            {
                board[m.x][m.y]->setFlag(chessEnum::enablePassan);
            }
            if(killerPiece->getType() == chessEnum::pawn)
            {
                if(turn == chessEnum::white)
                {
                    if(m.x - 1 >= 0 && board[m.x - 1][m.y]->getFlag() == chessEnum::passan)
                        board[m.x - 1][m.y]->setColor(Qt::yellow);

                    if(m.x + 1 <= 7 && board[m.x + 1][m.y]->getFlag() == chessEnum::passan)
                        board[m.x + 1][m.y]->setColor(Qt::yellow);
                }
                if(turn == chessEnum::black)
                {
                    if(m.x - 1 >= 0 && board[m.x - 1][m.y]->getFlag() == chessEnum::passan)
                        board[m.x - 1][m.y]->setColor(Qt::yellow);

                    if(m.x + 1 <= 7 && board[m.x + 1][m.y]->getFlag() == chessEnum::passan)
                        board[m.x + 1][m.y]->setColor(Qt::yellow);
                }
            }
        }
    }
    // Moves for king
    if(killerPiece->getType() == chessEnum::king)
    {
        auto elements = piecesWhite;
        if(turn == chessEnum::white) elements = piecesBlack;
        else elements = piecesWhite;
        for(auto wB : elements)
        {
            if(wB->Alive() == chessEnum::alive)
            {
                auto killMoves = wB->getMoves();
                for(auto m : killMoves)
                {
                    board[m.x][m.y]->setFlag(chessEnum::toKill);
                }
            }
        }
        for(auto m : moves)
        {
            if(board[m.x][m.y]->getFlag() != chessEnum::toKill) board[m.x][m.y]->setColor(Qt::yellow);
        }
    }
    // Castling
    if(killerPiece->getType() == chessEnum::king && killerPiece->isMoved() == chessEnum::notMoved)
    {
        // White right castling
        if(board[5][7]->getBoxState() == chessEnum::none && board[6][7]->getBoxState() == chessEnum::none &&
            board[7][7]->getPiece()->isMoved() == chessEnum::notMoved)
        {
            board[7][7]->setColor(Qt::yellow);
            board[7][7]->setFlag(chessEnum::castling);
        }
        // White left castling
        if(board[3][7]->getBoxState() == chessEnum::none && board[2][7]->getBoxState() == chessEnum::none &&
            board[1][7]->getBoxState() == chessEnum::none && board[0][7]->getPiece()->isMoved() == chessEnum::notMoved)
        {
            board[0][7]->setColor(Qt::yellow);
            board[0][7]->setFlag(chessEnum::castling);
        }
        // Black right castling
        if(board[5][0]->getBoxState() == chessEnum::none && board[6][0]->getBoxState() == chessEnum::none &&
            board[7][0]->getPiece()->isMoved() == chessEnum::notMoved)
        {
            board[7][0]->setColor(Qt::yellow);
            board[7][0]->setFlag(chessEnum::castling);
        }
        // Black left castling
        if(board[3][0]->getBoxState() == chessEnum::none && board[2][0]->getBoxState() == chessEnum::none &&
            board[1][0]->getBoxState() == chessEnum::none && board[0][0]->getPiece()->isMoved() == chessEnum::notMoved)
        {
            board[0][0]->setColor(Qt::yellow);
            board[0][0]->setFlag(chessEnum::castling);
        }
    }
}
