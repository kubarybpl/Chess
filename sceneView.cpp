
#include "sceneView.h"

sceneView::sceneView(QWidget *parent) : QGraphicsView(parent)
{
    settings = new settingsScene();
    menu = new menuScene(this);
    //game = new gameScene();



    //this->resize(800,600);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //this->ensureVisible(scene->sceneRect());
    //this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setMinimumSize(800,600);

    this->setScene(menu);
    this->show();


    connect(menu, &menuScene::settingsReq, this, &sceneView::toSettings);
    connect(menu, &menuScene::exitReq, this, &sceneView::exitRequest);
    //connect(menu, &menuScene::gameReq, this, &sceneView::toGame);
    //connect(game, &gameScene::menuReq, this, &sceneView::toMenu);
    //connect(settings, &settingsScene::menuReq, this, &sceneView::toMenu);
}

sceneView::~sceneView()
{

}
void sceneView::toSettings()
{
    this->setScene(settings);
    this->show();
}
/*
void sceneView::toGame()
{

    this->setScene(game);
    this->show();

}

void sceneView::toMenu()
{
    this->setScene(menu);
    this->show();
    game->dialog->close();
    //delete game;
}
*/
void sceneView::exitRequest()
{
    emit exitReq();
}
