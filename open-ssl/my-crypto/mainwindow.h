#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QString>

#include <memory>

extern "C"
{
#include <openssl/md5.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_MD5_clicked();

    void on_PushButton_genPrivateKey_clicked();

    void on_pushButton_Code_clicked();

private:
    Ui::MainWindow *ui;

    QDir mCurDir;
    QString mPlainText;
    QString mPrivateKey;
    QString mStrForEncrypting {"String for RSA encripting"};

private:
    const int kBits = 1024;
    const int kExp = 3;

    using RSA_ptr = std::unique_ptr<RSA, decltype(&::RSA_free)>;
    RSA_ptr rsa;

};

#endif // MAINWINDOW_H
