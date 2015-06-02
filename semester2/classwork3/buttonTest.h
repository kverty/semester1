#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "findpair.h"

#include <time.h>

class ButtonTest : public QObject
{
   Q_OBJECT
public:
   explicit ButtonTest(QObject *parent = 0) : QObject(parent) {}


private slots:
    void testFourTypes()
    {
        int *newArray = makeArray(14, 4);
        int *countOfCards = new int[4];

        for (int i = 0; i < 4; i++)
            countOfCards[i] = 0;

        for (int i = 0; i < 14; i++)
            countOfCards[newArray[i]]++;

        for (int i = 0; i < 4; i++)
            QVERIFY(countOfCards[i] % 2 == 0);
    }

    void testBinaryArray()
    {
        int *newArray = makeArray(10, 2);
        int *countOfCards = new int[2];

        for (int i = 0; i < 2; i++)
            countOfCards[i] = 0;

        for (int i = 0; i < 10; i++)
            countOfCards[newArray[i]]++;

        for (int i = 0; i < 2; i++)
            QVERIFY(countOfCards[i] % 2 == 0);
    }
};

