
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

/*private slots:
    void settingsToMenu();
    void switchToScene2();
*/
public slots:
    void toMenu();
    void toSettings();
signals:
    void toMenuReq();
    void toSettingsReq();
private:
    menuScene *menu;
    settingsScene *settings;
    //gameScene *game;


};

#endif // SCENEVIEW_H
