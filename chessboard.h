
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <vector>
#include "chessbox.h"
#include "pawn.h"

class chessBox;
class pawn;
class chessBoard : public QObject
{
    Q_OBJECT
public:
    chessBoard(qreal x = 0, qreal y = 0, qreal s = 50, QGraphicsScene *parent = nullptr);
    void drawPieces(piece *element);
    void setState(chessEnum newState);
    void showMoves(std::vector<std::vector<int>> moves);
    void resetColors();
    void addPiece(piece* element);
    void removePiece(piece* element);
    chessEnum getTurn();
    chessEnum getState();
    chessEnum getBoxState(int x, int y);
private:
    chessBox *board[8][8];
    QGraphicsScene *parentPtr;
    qreal x;
    qreal y;
    qreal s;
    QGraphicsRectItem *rect;
    QGraphicsTextItem *text;
    pawn *pionek;
    chessEnum state;
    chessEnum turn;

};

#endif // CHESSBOARD_H
