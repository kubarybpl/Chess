
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chessbox.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class chessBoard : public QObject
{
    Q_OBJECT
public:
    chessBoard(qreal x = 0, qreal y = 0, qreal s = 50, QGraphicsScene *parent = nullptr);
private:
    chessBox *board[8][8];
    qreal x;
    qreal y;
    qreal s;
    QGraphicsRectItem *rect;
    QGraphicsTextItem *text;
};

#endif // CHESSBOARD_H
