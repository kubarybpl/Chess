
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
    sceneView(QGraphicsScene *scene, QWidget *parent = nullptr);
    ~sceneView();

private:
    //menuScene *menu;
    //settingsScene *settings;
    //gameScene *game;


};

#endif // SCENEVIEW_H
