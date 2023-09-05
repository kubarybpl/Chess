
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <vector>
#include "chessbox.h"
#include "pawn.h"

enum class action {select, move};

class chessBox;
class chessBoard : public QObject
{
    Q_OBJECT
public:
    chessBoard(qreal x = 0, qreal y = 0, qreal s = 50, QGraphicsScene *parent = nullptr);
    void drawPieces(piece *element);
    action getState();
    void setState(action newState);

private:
    chessBox *board[8][8];
    QGraphicsScene *parentPtr;
    qreal x;
    qreal y;
    qreal s;
    QGraphicsRectItem *rect;
    QGraphicsTextItem *text;
    //vector<piece*>
    pawn *pionek;
    action state;

};

#endif // CHESSBOARD_H
