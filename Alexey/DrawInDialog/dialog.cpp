#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include "QDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);    
    timerId = startTimer(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_pressed()
{
     close();
}

void Dialog::on_pushButton_2_pressed()
{
    drawShapes = !drawShapes;
    update();
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(drawShapes)
    {
        QRectF rectangle(10.0, 20.0, 80.0, 60.0);
        int startAngle = 30 * 16;
        int spanAngle = 120 * 16;
        painter.drawArc(rectangle, startAngle, spanAngle);
    }
    QRectF rect2(10.0, 20.0, 80.0, 60.0);
    rect2.moveTo(m_X,m_Y);
    painter.drawEllipse(rect2);
}

void Dialog::timerEvent(QTimerEvent *event)
{
    m_X+=10;
    m_Y+=10;
    update();
    //qDebug() << "Update...";
}
