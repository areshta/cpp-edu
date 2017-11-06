#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "btview.h"
#include "btmodel.h"

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
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    Ui::Dialog *ui;

    BtModel mBtModel;
    BtView mBtVew;    
};

#endif // DIALOG_H
