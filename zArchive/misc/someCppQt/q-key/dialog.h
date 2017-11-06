#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    bool eventFilter(QObject *object, QEvent *e);

    void MyDraw();
    int mX = 50;
    int mY = 50;
    int dX = 5;
    int dY = 5;

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
