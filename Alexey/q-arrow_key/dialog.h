#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QEvent>

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
    void paintEvent(QPaintEvent *);

    int mX=50;
    int mY=50;
    int mW=100;
    int mH=10;
    int dX=5;
    int dY=5;

    Ui::Dialog *ui;
};

#endif // DIALOG_H
