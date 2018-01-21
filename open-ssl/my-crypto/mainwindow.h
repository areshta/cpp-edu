#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QString>

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

    void on_pushButton_getPublicKey_clicked();

private:
    Ui::MainWindow *ui;

    QDir mCurDir;
    QString mPlainText;
    QString mPrivateKey;
};

#endif // MAINWINDOW_H
