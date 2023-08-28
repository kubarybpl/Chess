
#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H

#include <QGraphicsScene>
#include <QLabel>
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
    QLabel *label;
public slots:
    void menuButtonClicked();
    void costamButtonClicked();
signals:
    void toMenuReq();
};

#endif // SETTINGSSCENE_H
