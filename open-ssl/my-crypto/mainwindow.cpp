#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

#include <cstring>
#include <openssl/err.h>
#include <array>
#include <string>
#include <iomanip>
#include <sstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    rsa(RSA_generate_key(kBits, kExp, 0, 0), ::RSA_free)
{
    ui->setupUi(this);
    ui->textBrowser_forEncrypting->setText(mStrForEncrypting);
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
    if(mPlainText.toLatin1().size() != 0){
        std::array<unsigned char, MD5_DIGEST_LENGTH> aDigest;
        MD5(reinterpret_cast<unsigned char*>(mPlainText.toLatin1().data()),
            mPlainText.toLatin1().size(),
            aDigest.data());
        std::stringstream stream;
        stream.str().reserve(MD5_DIGEST_LENGTH*2);
        for(auto dg: aDigest){
           stream << std::hex << std::setprecision(2) << static_cast<int>(dg);
        }
        ui->label_MD5->setText(stream.str().c_str());
    } else {
        ui->label_MD5->setText("Input field is empty!");
    }

}

void MainWindow::on_PushButton_genPrivateKey_clicked()
{
    int keylen = 0;

    /* To get the C-string PEM form: */
    using BIO_ptr = std::unique_ptr<BIO, decltype(&::BIO_free_all)>;
    BIO_ptr bio(BIO_new(BIO_s_mem()), ::BIO_free_all);
    PEM_write_bio_RSAPrivateKey(bio.get(), rsa.get(), NULL, NULL, 0, NULL, NULL);
    keylen = BIO_pending(bio.get());

    using char_ptr = std::unique_ptr<unsigned char>;
    char_ptr pem_key (new unsigned char[keylen+1]); /* Null-terminate */

    BIO_read(bio.get(), pem_key.get(), keylen);
    ui->textBrowser_PrivatKey->setText(reinterpret_cast<char*>(pem_key.get()));

    PEM_write_bio_RSAPublicKey(bio.get(), rsa.get());
    keylen = BIO_pending(bio.get());
    BIO_read(bio.get(), pem_key.get(), keylen);
    ui->textBrowser_PublicKey->setText(reinterpret_cast<char*>(pem_key.get()));


}


void MainWindow::on_pushButton_Code_clicked()
{
    std::array<unsigned char, kBits/8>(encrypt);

    int txtStrLen = mStrForEncrypting.toLatin1().size();
    int encrypt_len = RSA_public_encrypt(
               txtStrLen,
               reinterpret_cast<unsigned char *>(mStrForEncrypting.toLatin1().data()),
               encrypt.data(),
               rsa.get(),
               RSA_PKCS1_OAEP_PADDING);

    QString sEncrypting;
    for(auto ch: encrypt){
        sEncrypting += QString::number(static_cast<int>(ch));
        sEncrypting += " ";
    }

    ui->textBrowser_Encrypted->setText(sEncrypting);

   std::array<unsigned char, kBits/8>(decrypt) {0};
   if(RSA_private_decrypt(
               encrypt_len,
               encrypt.data(),
               decrypt.data(),
               rsa.get(), RSA_PKCS1_OAEP_PADDING) == -1) {
      ERR_load_crypto_strings();
      std::array<char, 256>(err) {0};
      ERR_error_string(ERR_get_error(), err.data());
      qDebug() << "Error decrypting message:" << err.data();
      ERR_free_strings();
   } else {
       ui->textBrowser_Decrypted->setText(reinterpret_cast<char*>(decrypt.data()));
   }
}
