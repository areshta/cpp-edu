#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    void timerEvent(QTimerEvent *event);

private:
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

private:
    Ui::Dialog *ui;
    bool drawShapes = false;
    int timerId;
    int m_X = 0;
    int m_Y = 0;
};

#endif // DIALOG_H
