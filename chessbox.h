
#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>

class chessBox : public QGraphicsRectItem
{
    //Q_OBJECT
public:
    chessBox(qreal x = 0, qreal y = 0, qreal s = 50, QGraphicsItem *parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    qreal x;
    qreal y;
    qreal s;
};

#endif // CHESSBOX_H
