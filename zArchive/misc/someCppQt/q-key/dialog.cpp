#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QDebug>
#include <QEvent>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //MyDraw();
    //update();
}

void Dialog::MyDraw()
{
    QPainter painter;

    painter.begin(this);

       QRectF rectangle(10.0, 20.0, 80.0, 60.0);
        int startAngle = 30 * 16;
        int spanAngle = 120 * 16;
        painter.drawArc(rectangle, startAngle, spanAngle);

     painter.end();
}

bool Dialog::eventFilter(QObject *object, QEvent *e)
{

}

Dialog::~Dialog()
{
    delete ui;
}
