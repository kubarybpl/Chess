
#include "menuScene.h"

menuScene::menuScene() : QGraphicsScene()
{

    this->setSceneRect(0, 0, 800, 600);
    this->addRect(10, 10, 200, 200, QPen(), QBrush(Qt::blue));
    gameButton = new button("Rozpocznij gre");
    gameButton->move(400,300);

    label = new QLabel("Ekran menu");
    label->setAlignment(Qt::AlignHCenter);
    this->addWidget(label);

    settingsButton = new button("Ustawienia");
    settingsButton->move(400,250);
    connect(settingsButton, &QPushButton::clicked, this, &menuScene::settingsButtonClicked);

    this->addWidget(gameButton);
    this->addWidget(settingsButton);

}

menuScene::~menuScene()
{

}

void menuScene::settingsButtonClicked()
{
    //qDebug() << "Z menu->settingsButtonClicked";
    emit toSettingsReq();
}
void menuScene::gameButtonClicked()
{

}
