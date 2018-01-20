#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

#include <cstring>

extern "C"
{
#include <openssl/md5.h>
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mCurDir.setPath("../cpp-edu/open-ssl/my-crypto-data/plain.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog fDlg;

    fDlg.setDirectory(mCurDir);
    //fDlg.show();

    QString flName = fDlg.getOpenFileName();
    ui->fileTextEdit->setPlainText(flName);

    QFile fl(flName);

    fl.open(QIODevice::ReadOnly| QIODevice::Text);

    mPlainText = fl.readAll();

    qDebug() << mPlainText;

    ui->plainTextBrowser->setText(mPlainText);

}

void MainWindow::on_genKeysButton_clicked()
{





}

void MainWindow::on_pushButton_MD5_clicked()
{
    unsigned char digest[MD5_DIGEST_LENGTH];

    char *inBuff = mPlainText.toLatin1().data();


    if(mPlainText.toLatin1().size() != 0){
        MD5(reinterpret_cast<unsigned char*>(inBuff), mPlainText.toLatin1().size(), digest);
        char mdString[33] = {0};
        for(int i = 0; i < 16; i++){
            sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
        }
        ui->label_MD5->setText(mdString);
    } else {
        ui->label_MD5->setText("No Input!");
    }

}
