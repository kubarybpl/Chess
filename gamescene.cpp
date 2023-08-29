
#include "gamescene.h"

gameScene::gameScene() : QGraphicsScene()
{
    this->setSceneRect(0, 0, 800, 600);

    menuButton = new button("Powrót do menu");
    menuButton->move(this->width()*0.75,this->height()*0.25);
    this->addWidget(menuButton);

    textItem = new QGraphicsTextItem("Ekran gry");
    textItem->setPos(this->width()/2,0);
    this->addItem(textItem);

    board = new chessBoard(100,100,this);


    connect(menuButton, &QPushButton::clicked, this, &gameScene::menuButtonClicked);

}

gameScene::~gameScene()
{

}

void gameScene::menuButtonClicked()
{
    emit menuReq();
}
