
#include "gamescene.h"
#include <QDebug>
gameScene::gameScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 800, 600);

    menuButton = new button("Powrót do menu");
    menuButton->move(this->width()*0.85,this->height()*0.05);
    this->addWidget(menuButton);

    //timerWhite = new QTimer(this);
    //timerWhite->setSingleShot(true);
    //timerWhite->

    gameLabel = new QLabel("Ekran gry");
    gameLabel->move(this->width()/2, 0);
    this->addWidget(gameLabel);

    sizeBox = 60;
    board = new chessBoard((this->width() - 8*sizeBox)/2,(this->height() - 8*sizeBox)/2,sizeBox,this);

    connect(menuButton, &QPushButton::clicked, this, &gameScene::menuButtonClicked);

}

gameScene::~gameScene()
{

}

void gameScene::menuButtonClicked()
{
    dialEndButton = new button("Zakończ grę");
    dialCancelButton = new button("Anuluj");
    dialBox = new QDialogButtonBox(Qt::Horizontal);
    dialBox->addButton(dialEndButton, QDialogButtonBox::AcceptRole);
    dialBox->addButton(dialCancelButton, QDialogButtonBox::RejectRole);
    QLabel *info = new QLabel("Czy na pewno chcesz opuścić grę?\nPostępy zostaną utracone");
    QVBoxLayout *layout= new QVBoxLayout();
    layout->addWidget(dialBox);
    layout->addWidget(info);
    dialog = new QDialog();
    dialog->setLayout(layout);
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    connect(dialEndButton, &QPushButton::clicked, this, &gameScene::menuReq);
    connect(dialCancelButton, &QPushButton::clicked, dialog, &QDialog::close);
    dialog->exec();

    //emit menuReq();
}
