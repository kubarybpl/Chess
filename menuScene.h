
#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsRectItem>
#include "button.h"
#include "button.h"

class menuScene : public QGraphicsScene
{
    Q_OBJECT
public:
    menuScene();
    ~menuScene();

    QLabel *label;

public slots:
    void settingsButtonClicked();
    void gameButtonClicked();
signals:
    void toMenuReq();
    void toSettingsReq();
private:
    button *gameButton;
    button *settingsButton;
};

#endif // MENUSCENE_H
