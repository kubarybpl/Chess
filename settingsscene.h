
#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H

#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsTextItem>
#include "button.h"

class settingsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    settingsScene();
    ~settingsScene();
private:
    button *menuButton;
    button *costamButton;
    QGraphicsTextItem *textItem;
public slots:
    void menuButtonClicked();
    void costamButtonClicked();
signals:
    void menuReq();
};

#endif // SETTINGSSCENE_H
