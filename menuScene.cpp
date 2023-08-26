
#include "menuScene.h"

menuScene::menuScene() : QGraphicsScene()
{
    this->setSceneRect(0, 0, 800, 600);
    this->addRect(10, 10, 200, 200, QPen(), QBrush(Qt::blue)); // Przykład dodawania prostokąta

}

menuScene::~menuScene()
{

}
