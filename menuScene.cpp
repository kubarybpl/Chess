
#include "menuScene.h"

menuScene::menuScene() : QGraphicsScene()
{

    this->setSceneRect(0, 0, 800, 600);
    this->addRect(100, 100, 200, 200, QPen(), QBrush(Qt::blue));

    gameButton = new button("Rozpocznij gre");
    gameButton->move(400,300);
    this->addWidget(gameButton);

    textItem = new QGraphicsTextItem("Ekran początkowy");
    textItem->setPos(this->width()/2.0,0);
    this->addItem(textItem);

    exitButton = new button("Wyjdź z gry");
    exitButton->move(400,350);
    this->addWidget(exitButton);

    settingsButton = new button("Ustawienia");
    settingsButton->move(400,250);
    this->addWidget(settingsButton);

    connect(settingsButton, &QPushButton::clicked, this, &menuScene::settingsButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &menuScene::exitButtonClicked);
    connect(gameButton, &QPushButton::clicked, this, &menuScene::gameButtonClicked);
}

menuScene::~menuScene()
{

}

void menuScene::settingsButtonClicked()
{
    emit settingsReq();
}

void menuScene::gameButtonClicked()
{
    emit gameReq();
}

void menuScene::exitButtonClicked()
{
    emit exitReq();
}
