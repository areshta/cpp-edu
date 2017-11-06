#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QDialog>

class MyButton: public QPushButton
{
public:
    MyButton(QDialog* d){};
};
#endif // MYBUTTON_H
