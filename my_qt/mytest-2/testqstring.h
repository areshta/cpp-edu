#ifndef TESTQSTRING_H
#define TESTQSTRING_H
#include <QtTest/QtTest>

#include <QObject>

class TestQString : public QObject
{
    Q_OBJECT

private slots:
void toUpper();
};

#endif // TESTQSTRING_H

