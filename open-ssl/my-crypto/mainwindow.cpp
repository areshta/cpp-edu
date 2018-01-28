#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

#include <cstring>
#include <openssl/err.h>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    rsa(RSA_generate_key(kBits, kExp, 0, 0), ::RSA_free)
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

    QString strForEncrypting = ui->label_CodingStr->text();

    char *msg = strForEncrypting.toLatin1().data();
    int len = strnlen(msg,100)+1;
    unsigned char *encrypt = new unsigned char[kBits/8];

   int encrypt_len = RSA_public_encrypt(len, reinterpret_cast<unsigned char *>(msg), encrypt, rsa.get(), RSA_PKCS1_OAEP_PADDING);
    qDebug() << "len = " << len << "msg" << msg << "   encrypt_len" << encrypt_len;

    /////RSA_public_encrypt(strlen(msg)+1, (unsigned char*)msg,(unsigned char*)encrypt, keypair, RSA_PKCS1_OAEP_PADDING))


   char *decrypt = (char*)malloc(kBits/8);
   if(RSA_private_decrypt(encrypt_len, (unsigned char*)encrypt, (unsigned char*)decrypt,
                          rsa.get(), RSA_PKCS1_OAEP_PADDING) == -1) {
      ERR_load_crypto_strings();
      char err[256];
      ERR_error_string(ERR_get_error(), err);
      qDebug() << "Error decrypting message:" << err;
      ERR_free_strings();
      } else {
       qDebug() << "Decrypted message:" << decrypt;
   }

    delete[] decrypt;
    delete[] encrypt;
}
