#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QRect>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    qDebug() << "Start";
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect rect(mX,mY,mW,mH);
    painter.drawRect(rect);
}


bool Dialog::eventFilter(QObject *object, QEvent *e)
{

    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if( Qt::Key_Left == keyEvent->key() ){
            mX-=dX ;
        }
        else if( Qt::Key_Right == keyEvent->key() ){
            mX+=dX; ;
        }
        update();
    }
    return false;
}

Dialog::~Dialog()
{
    delete ui;
}
