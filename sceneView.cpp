
#include "sceneView.h"

sceneView::sceneView(QWidget *parent) : QGraphicsView(parent)
{
    //settings = new settingsScene();
    menu = new menuScene(this);


    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setMinimumSize(800,600);

    this->setScene(menu);
    this->show();


    connect(menu, &menuScene::settingsReq, this, &sceneView::toSettings);
    connect(menu, &menuScene::exitReq, this, &sceneView::exitRequest);
}

sceneView::~sceneView()
{

}
void sceneView::toSettings()
{
    this->setScene(settings);
    this->show();
}

void sceneView::exitRequest()
{
    emit exitReq();
}
