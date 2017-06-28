#include "dialog.h"
#include "ui_dialog.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);   
    this->setFixedSize(GConst::Begin*3 + (GConst::CellSz+GConst::Margin) * GConst::ChessSz *2 ,
                       GConst::Begin*2 + (GConst::CellSz+GConst::Margin) * GConst::ChessSz);
    setMouseTracking(true);
}

Dialog::~Dialog()
{
    delete ui;    
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    mBtVew.Draw(painter);
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if( mBtVew.OnMouseMove( event->pos() ) )
    {
        update();
    }
    //qDebug() << event->pos();
}

