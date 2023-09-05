
#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <pawn.h>
#include <chessboard.h>

enum class state {occupied, free};

class chessBoard;
class chessBox : public QGraphicsRectItem
{
    //Q_OBJECT
public:
    chessBox(qreal x = 0, qreal y = 0, qreal s = 50, chessBoard *object = nullptr, QGraphicsItem *parent = nullptr);
    void drawPiece(piece *element);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    chessBoard *parentPtr;
    qreal x;
    qreal y;
    qreal s;
    QPen pen;
    state boxState;
    team side;

};

#endif // CHESSBOX_H
