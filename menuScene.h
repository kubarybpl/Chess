
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
#include "settingsscene.h"

#include <QGraphicsView>


class menuScene : public QGraphicsScene
{
    Q_OBJECT
public:
    menuScene(QObject *parent = nullptr);
    ~menuScene();
public slots:
    void settingsButtonClicked();
    void exitButtonClicked();
    void toGame();
    void gameToMenu();
    void settingsToMenu();
signals:
    void settingsReq();
    void exitReq();
private:
    button *gameButton;
    button *settingsButton;
    button *exitButton;
    QLabel *labelMenu;
    gameScene *game;
    settingsScene *settings;

    QGraphicsView *parentPtr;
};

#endif // MENUSCENE_H
