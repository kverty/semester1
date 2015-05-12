#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "sharedPointer.h"

class SharedPtrTest : public QObject
{
   Q_OBJECT
public:
   explicit SharedPtrTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testConstructor()
    {
        SharedPtr<int> pointer(new int(10));
        QVERIFY(pointer.refCount() == 1);
        QVERIFY(*pointer.object() == 10);
    }

    void testCopyConstructor()
    {
        SharedPtr<double> pointer1(new double(0.5));
        SharedPtr<double> pointer2(pointer1);
        QVERIFY(pointer1.refCount() == 2);
        QVERIFY(pointer2.refCount() == 2);
        QVERIFY(*pointer1.object() == 0.5);
        QVERIFY(*pointer2.object() == 0.5);
        QVERIFY(pointer1.object() == pointer2.object());
    }

    void testOperatorEqual()
    {
        SharedPtr<char> pointer1(new char('a'));
        SharedPtr<char> pointer2(new char('b'));
        SharedPtr<char> pointer3(new char('c'));
        SharedPtr<char> pointer4 = pointer1;

        QVERIFY(pointer1.refCount() == 2);
        pointer3 = pointer2;

        QVERIFY(pointer2.refCount() == 2);
        QVERIFY(pointer3.refCount() == 2);
        QVERIFY(*pointer3.object() == *pointer2.object());

    }
};
