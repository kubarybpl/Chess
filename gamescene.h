
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsTextItem>
#include "button.h"
#include "chessboard.h"

class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    gameScene();
    ~gameScene();
private:
    button *menuButton;
    QGraphicsTextItem *textItem;
    chessBoard *board;
public slots:
    void menuButtonClicked();
signals:
    void menuReq();
};

#endif // GAMESCENE_H
