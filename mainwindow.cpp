
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sceneView.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menuScene *menu = new menuScene();
    sceneView *widok = new sceneView(menu, this);

    widok->setScene(menu);
    widok->show();
    //widok->fitInView(menu->sceneRect(), Qt::KeepAspectRatio);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *centralLayout = new QVBoxLayout;

    // Dodawanie QGraphicsView do layoutu w centralWidget
    centralLayout->addWidget(widok);
    centralWidget->setLayout(centralLayout);

    // Ustawianie centralWidget w głównym oknie
    setCentralWidget(centralWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


