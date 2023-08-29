
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //menuScene *menu = new menuScene();
    //settingsScene *settings= new settingsScene();
    widok = new sceneView(this);


    //widok->setScene(menu);
    //widok->show();
    //widok->fitInView(menu->sceneRect(), Qt::KeepAspectRatio);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *centralLayout = new QVBoxLayout;

    // Dodawanie QGraphicsView do layoutu w centralWidget
    centralLayout->addWidget(widok);
    centralWidget->setLayout(centralLayout);

    // Ustawianie centralWidget w głównym oknie
    setCentralWidget(centralWidget);

    connect(widok, &sceneView::exitReq, this, &MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onExitReq()
{
    //this->widok->menu->label->setText("z main");
}


