
#include "button.h"

button::button(const QString &name, QWidget *parent) : QPushButton(name, parent)
{
    //this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->resize(70,30);
}

button::~button()
{

}

