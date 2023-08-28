
#ifndef BUTTON_H
#define BUTTON_H

#include<QPushButton>

class button : public QPushButton
{
    Q_OBJECT
public:
    button(const QString &name, QWidget *parent = nullptr);
    ~button();
signals:
    void buttonClicked();
};
#endif // BUTTON_H
