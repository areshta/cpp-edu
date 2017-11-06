#include <QCoreApplication>
#include <QDebug>

int& f()
{
    int *pTmp = new int[100];
    pTmp[0] = 555;
    return pTmp[0];

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int aa;

    qDebug()<< f() << aa;
    qDebug()<< "memory leaks & ref to temporary";

    return a.exec();
}
