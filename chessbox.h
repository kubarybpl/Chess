
#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include "piece.h"
#include "chessboard.h"
#include "chessenum.h"

class chessBoard;
class chessBox : public QGraphicsRectItem
{
    //Q_OBJECT
public:
    chessBox(qreal x = 0, qreal y = 0, qreal s = 50, int col = 0, int row = 0, chessBoard *object = nullptr, QGraphicsItem *parent = nullptr);
    void drawPiece(piece *element);
    void setBoxState(chessEnum state);
    void setColor(QBrush brush);
    void setPiece(piece *element);
    void setFlag(chessEnum);
    chessEnum getFlag();
    chessEnum getBoxState();
    QBrush getColor();
    piece *getPiece();
    void disableClick();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    chessBoard *boardPtr;
    QBrush color;
    bool accept;
    int row;
    int col;
    qreal s;
    QPen pen;
    chessEnum boxState;
    chessEnum flag;
    piece *currentPiece;
};

#endif // CHESSBOX_H
