
#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>

enum class team {white, black, none};

class piece : public QGraphicsPixmapItem
{
public:
    piece(team color);
    void returnColor();
    void drawPiece();
    virtual void setImage() = 0;
    team getTeam();
private:
    int row;
    int col;
    team player;
};

#endif // PIECE_H
