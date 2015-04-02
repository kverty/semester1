#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include <time.h>
#include "output.h"
#include "outToConsole.h"
#include "outToFile.h"

class OutputTest : public QObject
{
   Q_OBJECT
public:
   explicit OutputTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///test for method squareToLinear()
    void testSquareToLinear()
    {
        int* *array = new int*[3];
        for (int i = 0; i < 3; i++)
            array[i] = new int[3];

        array[1][1] = 1;
        array[0][1] = 2;
        array[0][0] = 3;
        array[1][0] = 4;
        array[2][0] = 5;
        array[2][1] = 6;
        array[2][2] = 7;
        array[1][2] = 8;
        array[0][2] = 9;

        Output *output = new ConsoleOutput(array, 3);

        int *result = output->squareToLinear(array, 3);
        for (int i = 1; i <= 9; i++)
            QVERIFY(result[i - 1] == i);
    }
};
