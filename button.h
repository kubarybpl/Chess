
#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QWidget>


class button : public QPushButton
{
public:
    button(const QString &name, QWidget *parent = nullptr);
    ~button();
private:

};

#endif // BUTTON_H
