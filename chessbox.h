
#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
//#include "pawn.h"
//#include "bishop.h"
//#include "knight.h"
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
    void movePiece();
    chessEnum getBoxState();
    QBrush getColor();
    void setColor(QBrush brush);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    chessBoard *boardPtr;
    QBrush color;
    int row;
    int col;
    qreal s;
    QPen pen;
    chessEnum boxState;
    piece *currentPiece;
    static piece *killerPiece;
    static chessBox *previousBox;



};

#endif // CHESSBOX_H
