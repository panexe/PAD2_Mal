#ifndef TEST_H
#define TEST_H

#include <QtTest/QTest>

class test : public QObject
{
    Q_OBJECT

private slots:
    void Test();
public:
    test();
};

#endif // TEST_H
