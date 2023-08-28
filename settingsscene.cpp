
#include "settingsscene.h"


settingsScene::settingsScene() : QGraphicsScene()
{
    this->setSceneRect(0, 0, 800, 600);
    this->addRect(10, 10, 200, 200, QPen(), QBrush(Qt::red)); // Przykład dodawania prostokąta

    label = new QLabel("Ekran ustawień");
    label->setAlignment(Qt::AlignHCenter);

    menuButton = new button("Powrót do menu");
    menuButton->move(400,300);
    this->addWidget(menuButton);
    this->addWidget(label);

    connect(menuButton, &QPushButton::clicked, this, &settingsScene::menuButtonClicked);

}

settingsScene::~settingsScene()
{

}

void settingsScene::menuButtonClicked()
{
    emit toMenuReq();
}

void settingsScene::costamButtonClicked()
{

}
