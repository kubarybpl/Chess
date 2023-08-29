
#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsRectItem>
#include "button.h"
#include <QGraphicsTextItem>

class menuScene : public QGraphicsScene
{
    Q_OBJECT
public:
    menuScene();
    ~menuScene();
public slots:
    void settingsButtonClicked();
    void gameButtonClicked();
    void exitButtonClicked();
signals:
    void settingsReq();
    void exitReq();
    void gameReq();
private:
    button *gameButton;
    button *settingsButton;
    button *exitButton;
    QGraphicsTextItem *textItem;
};

#endif // MENUSCENE_H
