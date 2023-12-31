
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
    void toSettings();
    void exitRequest();
signals:
    void exitReq();
private:
    menuScene *menu;
    settingsScene *settings;
};

#endif // SCENEVIEW_H
