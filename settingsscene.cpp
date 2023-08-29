
#include "settingsscene.h"


settingsScene::settingsScene() : QGraphicsScene()
{
    this->setSceneRect(0, 0, 800, 600);
    this->addRect(10, 10, 200, 200, QPen(), QBrush(Qt::red)); // Przykład dodawania prostokąta

    textItem = new QGraphicsTextItem("Ekran ustawień");
    textItem->setPos(this->width()/2.0,0);
    this->addItem(textItem);

    menuButton = new button("Powrót do menu");
    menuButton->move(400,300);
    this->addWidget(menuButton);

    connect(menuButton, &QPushButton::clicked, this, &settingsScene::menuButtonClicked);
}

settingsScene::~settingsScene()
{
}

void settingsScene::menuButtonClicked()
{
    emit menuReq();
}

void settingsScene::costamButtonClicked()
{

}
