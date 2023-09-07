
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widok = new sceneView(this);

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
