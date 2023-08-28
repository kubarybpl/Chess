
#include "sceneView.h"

sceneView::sceneView(QWidget *parent) : QGraphicsView(parent)
{
    //menu = dynamic_cast<menuScene*>(scene);
    //settingsScene *settings= new settingsScene();
    settings = new settingsScene();
    menu = new menuScene();



    this->resize(800,600);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //this->ensureVisible(scene->sceneRect());
    //this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setMinimumSize(800,600);

    this->setScene(menu);
    this->show();

    //connect(buttonScene1, &QPushButton::clicked, this, &CustomGraphicsView::switchToScene1);
    //(buttonScene2, &QPushButton::clicked, this, &CustomGraphicsView::switchToScene2);

    connect(menu, &menuScene::toSettingsReq, this, &sceneView::toSettings);
    connect(settings, &settingsScene::toMenuReq, this, &sceneView::toMenu);


}

sceneView::~sceneView()
{

}
void sceneView::toSettings()
{
    this->setScene(settings);
    this->show();
}

void sceneView::toMenu()
{
    //menu = new menuScene();
    this->setScene(menu);
    this->show();
}
