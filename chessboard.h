
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <vector>
#include "chessbox.h"
#include "piece.h"
#include "bishop.h"
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

class gameScene;
class chessBox;
class chessBoard : public QObject
{
    Q_OBJECT
public:
    chessBoard(qreal x = 0, qreal y = 0, qreal s = 50, gameScene *parent = nullptr);
    void drawPieces();
    void setState(chessEnum newState);
    void showMoves(std::vector<myTemplate<int, chessEnum>> moves);
    void resetColors();
    void addPiece(piece* element);
    void movePiece(int X, int Y);
    void removePiece(piece* element);
    void changeTurn();
    void setKiller(piece* element);
    void setPrevBox(chessBox* box);
    void setSpecialMove(chessEnum move);
    void castling(int X, int Y);
    piece *giveKiller();
    chessBox *givePrevBox();
    chessEnum getTurn();
    chessEnum getState();
    chessEnum getBoxState(int x, int y);
private:
    chessBox *board[8][8];
    gameScene *parentPtr;
    qreal x;
    qreal y;
    qreal s;
    chessEnum specialMove;
    std::vector<piece*> piecesWhite;
    std::vector<piece*> piecesBlack;
    QGraphicsRectItem *rect;
    QGraphicsTextItem *text;

    chessEnum state;
    chessEnum turn;

    static piece *killerPiece;
    static chessBox *previousBox;
};

#endif // CHESSBOARD_H
