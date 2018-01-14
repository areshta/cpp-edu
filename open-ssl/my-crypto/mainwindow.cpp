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


    unsigned char digest[MD5_DIGEST_LENGTH];
    char string[] = "happy";

    MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

    char mdString[33];

    for(int i = 0; i < 16; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    // printf("md5 digest: %s\n", mdString);

    qDebug() << mdString;

/*
 unsigned char *MD5(const unsigned char *d, unsigned long n,
                  unsigned char *md);

 int MD5_Init(MD5_CTX *c);
 int MD5_Update(MD5_CTX *c, const void *data,
                  unsigned long len);
 int MD5_Final(unsigned char *md, MD5_CTX *c);
 */
}
