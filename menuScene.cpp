
#include "menuScene.h"

menuScene::menuScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 800, 600);
    this->addRect(100, 100, 200, 200, QPen(), QBrush(Qt::blue));

    game = new gameScene();

    gameButton = new button("Rozpocznij gre");
    gameButton->move(400,300);
    this->addWidget(gameButton);

    labelMenu = new QLabel("Ekran początkowy");
    labelMenu->move(this->width()/2.0, 0);
    this->addWidget(labelMenu);

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

