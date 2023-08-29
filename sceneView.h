
#ifndef SCENEVIEW_H
#define SCENEVIEW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "menuScene.h"
#include "settingsScene.h"
#include "gameScene.h"

class sceneView : public QGraphicsView
{
    Q_OBJECT
public:
    sceneView(QWidget *parent = nullptr);
    ~sceneView();
public slots:
    void toMenu();
    void toSettings();
    void toGame();
    void exitRequest();
signals:
    void exitReq();
private:
    menuScene *menu;
    settingsScene *settings;
    gameScene *game;


};

#endif // SCENEVIEW_H
