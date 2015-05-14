#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "bag.h"
#include <time.h>

class BagTest : public QObject
{
   Q_OBJECT
public:
   explicit BagTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void initTest()
    {
        srand(time(NULL));
        Bag<int> bag;
        QVERIFY(!bag.contains(rand() % 100));
    }

    void simpleAdditionTest()
    {
        Bag<int> bag;
        bag.addValue(3.5);
        QVERIFY(bag.contains(3.5));
    }

    void manyElementsAdditionTest()
    {
        Bag<int> bag;
        for (int i = 0; i < 10; i++)
            bag.addValue(i);

        for (int i = 0; i < 10; i++)
             QVERIFY(bag.contains(i));
    }

    void simpleDeletionTest()
    {
        Bag<char> bag;
        bag.addValue('a');
        QVERIFY_EXCEPTION_THROWN(bag.deleteValue('b');, ElementNotFoundException);
        try
        {
            bag.deleteValue('a');
            QVERIFY(!bag.contains('a'));
        }
        catch(ElementNotFoundException)
        {
            QVERIFY(false);
        }
    }

    void multipleDeletionTest()
    {
        Bag<int> bag;
        for (int i = 0; i < 20; i++)
            bag.addValue(i);

        try
        {
            for (int i = 0; i < 20; i++)
                bag.deleteValue(i);
        }
        catch(ElementNotFoundException)
        {
            QVERIFY(false);
        }

        for (int i = 0; i < 20; i++)
            QVERIFY(!bag.contains(i));
    }
};

