#pragma once


#include <QtCore/QObject>
#include <QtTest/QTest>


//#include "binaryArray.h"

#include <time.h>


class ButtonTest : public QObject
{
   Q_OBJECT
public:
   explicit ButtonTest(QObject *parent = 0) : QObject(parent) {}


private slots:
    /*void testNumberOfOnes()
    {
        int *newArray = binaryArray(10);
        int numberOfOnes = 0;
        int numberOfZeros = 0;
        for (int i = 0; i < 10; i++)
        {
            if (newArray[i] == 1)
                numberOfOnes++;
            else
                numberOfZeros++;
        }

        QVERIFY(numberOfOnes % 2 == 0);
        QVERIFY(numberOfZeros % 2 == 0);
    }*/
};

