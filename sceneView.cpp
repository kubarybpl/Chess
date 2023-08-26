
#include "sceneView.h"

sceneView::sceneView(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(parent)
{
    this->resize(800,600);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->ensureVisible(scene->sceneRect());
    //this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

sceneView::~sceneView()
{

}

