
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QLabel>
#include <QDialogButtonBox>
#include "QDialog"
#include <QVBoxLayout>
#include <QTimer>
#include "button.h"
#include "chessboard.h"
class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    gameScene(QObject *parent = nullptr);
    ~gameScene();
    QDialog *dialog; // do poprawki
    void changeTurn(chessEnum color);
    void setState(chessEnum player);
    void gameOver(chessEnum player);
private:
    button *menuButton;
    button *dialEndButton;
    button *dialCancelButton;
    QLabel *gameLabel;
    QLabel *stateLabel;
    QLabel *dialLabel;
    chessBoard *board;
    qreal sizeBox;
    QDialogButtonBox *dialBox;

    QTimer *timerWhite;
    QTimer *timerBlack;

public slots:
    void menuButtonClicked();
    void closeDialog();

signals:
    void menuReq();
    void closeDial();
};

#endif // GAMESCENE_H
