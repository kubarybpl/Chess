
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chessbox.h"
#include <vector>
#include <QGraphicsScene>

class chessBoard : public QObject
{
    Q_OBJECT
public:
    chessBoard(qreal x = 0, qreal y = 0, QGraphicsScene *parent = nullptr);
private:
    std::vector<std::vector<chessBox*>> board;
    qreal x;
    qreal y;
};

#endif // CHESSBOARD_H
