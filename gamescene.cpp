
#include "gamescene.h"
#include <QDebug>

gameScene::gameScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 800, 600);

    menuButton = new button("Powrót do menu");
    menuButton->move(this->width()*0.85,this->height()*0.05);
    this->addWidget(menuButton);

    stateLabel = new QLabel("");
    stateLabel->move(this->width()/2 - 125, this->height()*9.4/10);
    QFont font("Arial", 16);
    stateLabel->setFont(font);
    stateLabel->setAlignment(Qt::AlignCenter);
    stateLabel->setStyleSheet("background: transparent; border: none;");
    stateLabel->setMinimumWidth(250);
    stateLabel->setMinimumHeight(30);
    this->addWidget(stateLabel);

    gameLabel = new QLabel("Runda białego");
    gameLabel->move(this->width()/2 - 125, 0);
    QFont font1("Arial", 16);
    gameLabel->setFont(font1);
    gameLabel->setAlignment(Qt::AlignCenter);
    gameLabel->setStyleSheet("background: transparent; border: none;");
    gameLabel->setMinimumWidth(250);
    gameLabel->setMinimumHeight(30);
    //gameLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
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

void gameScene::changeTurn(chessEnum color)
{
    if(color == chessEnum::black) gameLabel->setText("Runda czarnego");
    else gameLabel->setText("Runda białego");
}

void gameScene::setState(chessEnum player)
{
    if(player == chessEnum::none)
    {
        stateLabel->setText("");
        stateLabel->setStyleSheet("background: transparent; border: none;");
    }
    if(player == chessEnum::white)
    {
        stateLabel->setText("Biały za szachowany");
        stateLabel->setStyleSheet("border: 2px solid red;");
    }
    if(player == chessEnum::black)
    {
        stateLabel->setText("Czarny za szachowany");
        stateLabel->setStyleSheet("border: 2px solid red;");
    }
}

void gameScene::gameOver(chessEnum player)
{
    if(player == chessEnum::none)
    {
        stateLabel->setText("");
        stateLabel->setStyleSheet("background: transparent; border: none;");
    }
    if(player == chessEnum::white)
    {
        stateLabel->setText("Czarny wygrywa");
            stateLabel->setStyleSheet("border: 2px solid green;");
    }
    if(player == chessEnum::black)
    {
        stateLabel->setText("Biały wygrywa");
        stateLabel->setStyleSheet("border: 2px solid green;");
    }

}
