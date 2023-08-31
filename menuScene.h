
#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "button.h"
#include "gamescene.h"
class menuScene : public QGraphicsScene
{
    Q_OBJECT
public:
    menuScene(QObject *parent = nullptr);
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
    QLabel *labelMenu;
    gameScene *game;

};

#endif // MENUSCENE_H
