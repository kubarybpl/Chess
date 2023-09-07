
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

    dialog = nullptr;
    connect(menuButton, &QPushButton::clicked, this, &gameScene::menuButtonClicked);

}

void gameScene::menuButtonClicked()
{
    if(dialog == nullptr){
    dialEndButton = new button("Zakończ grę");
    dialCancelButton = new button("Anuluj");

    dialBox = new QDialogButtonBox(Qt::Horizontal);
    dialBox->addButton(dialEndButton, QDialogButtonBox::ActionRole);
    dialBox->addButton(dialCancelButton, QDialogButtonBox::RejectRole);
    dialLabel= new QLabel("Czy na pewno chcesz opuścić grę?\nPostępy zostaną utracone");
    QVBoxLayout *layout= new QVBoxLayout();
    layout->addWidget(dialLabel);
    layout->addWidget(dialBox);

    dialog = new QDialog();
    dialog->setLayout(layout);

    connect(dialEndButton, &QPushButton::clicked, this, &gameScene::menuReq);
    connect(dialCancelButton, &QPushButton::clicked, this, &gameScene::closeDialog);

    dialog->show();
    }
}

void gameScene::closeDialog()
{
    dialog->close();
    delete dialog;

    dialog = nullptr;

    dialCancelButton = nullptr;
    dialEndButton = nullptr;

    disconnect(dialEndButton, &QPushButton::clicked, this, &gameScene::menuReq);
    disconnect(dialCancelButton, &QPushButton::clicked, this, &gameScene::closeDialog);
}


gameScene::~gameScene()
{
}
