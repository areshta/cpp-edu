#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

#include <cstring>
#include <memory>

extern "C"
{
#include <openssl/md5.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
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

void MainWindow::on_PushButton_genPrivateKey_clicked()
{
    const int kBits = 1024;
    const int kExp = 3;
    using RSA_ptr = std::unique_ptr<RSA, decltype(&::RSA_free)>;
    RSA_ptr rsa(RSA_generate_key(kBits, kExp, 0, 0), ::RSA_free);

    /* To get the C-string PEM form: */
    using BIO_ptr = std::unique_ptr<BIO, decltype(&::BIO_free_all)>;
    BIO_ptr bio(BIO_new(BIO_s_mem()), ::BIO_free_all);
    PEM_write_bio_RSAPrivateKey(bio.get(), rsa.get(), NULL, NULL, 0, NULL, NULL);

    int keylen = BIO_pending(bio.get());
    using char_ptr = std::unique_ptr<unsigned char>;
    char_ptr pem_key (new unsigned char[keylen+1]); /* Null-terminate */
    BIO_read(bio.get(), pem_key.get(), keylen);

    ui->publickKeyBrowser->setText(reinterpret_cast<char*>(pem_key.get()));
    mPrivateKey = reinterpret_cast<char*>(pem_key.get());

}

void MainWindow::on_pushButton_getPublicKey_clicked()
{

}
