
#include "menuScene.h"
menuScene::menuScene(QObject *parent) : QGraphicsScene(parent)
{
    parentPtr = dynamic_cast<QGraphicsView*>(parent);
    this->setSceneRect(0, 0, 800, 600);

    game = new gameScene();
    settings = new settingsScene();

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
    connect(gameButton, &QPushButton::clicked, this, &menuScene::toGame);

    connect(settings, &settingsScene::menuReq, this, &menuScene::settingsToMenu);
    connect(game, &gameScene::menuReq, this, &menuScene::gameToMenu);
}

menuScene::~menuScene()
{

}

void menuScene::settingsButtonClicked()
{
    parentPtr->setScene(settings);
    parentPtr->show();
}


void menuScene::exitButtonClicked()
{
    emit exitReq();
}

void menuScene::toGame()
{
    if(game == nullptr) game = new gameScene(parentPtr);
    connect(game, &gameScene::menuReq, this, &menuScene::gameToMenu);
    parentPtr->setScene(game);
    parentPtr->show();

}

void menuScene::gameToMenu()
{
    game->closeDialog();
    parentPtr->setScene(this);
    parentPtr->show();
    delete game;
    game = nullptr;
    disconnect(game, &gameScene::menuReq, this, &menuScene::gameToMenu);
}

void menuScene::settingsToMenu()
{
    parentPtr->setScene(this);
    parentPtr->show();
}
