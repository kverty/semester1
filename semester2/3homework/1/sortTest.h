#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include <time.h>
#include "sort.h"
#include "bubblesort.h"
#include "qsort.h"
#include "insertionsort.h"

class SorterTest : public QObject
{
   Q_OBJECT
public:
   explicit SorterTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    /// tests constructor and method returnArray()
    void testWithoutSortBubble()
    {
        int size = 5;
        double *array = new double[size];

        for (int i = 0; i < size; i++)
            array[i] = i;

        Sorter *bubbleSorter = new BubbleSorter(array, size);
        double *newArray = bubbleSorter->returnArray();
        for (int i = 0; i < size; i++)
        {
            QVERIFY(newArray[i] == array[i]);
        }

        delete[] newArray;
        delete bubbleSorter;
    }

    void testWithoutSortInsert()
    {
        int size = 5;
        double *array = new double[size];

        for (int i = 0; i < size; i++)
            array[i] = i;

        Sorter *insertSorter = new InsertSorter(array, size);
        double *newArray = insertSorter->returnArray();
        for (int i = 0; i < size; i++)
        {
            QVERIFY(newArray[i] == array[i]);
        }

        delete[] newArray;
        delete insertSorter;
    }

    void testWithoutSortQuick()
    {
        int size = 5;
        double *array = new double[size];

        for (int i = 0; i < size; i++)
            array[i] = i;

        Sorter *qSorter = new QSorter(array, size);
        double *newArray = qSorter->returnArray();
        for (int i = 0; i < size; i++)
        {
            QVERIFY(newArray[i] == array[i]);
        }

        delete[] newArray;
        delete qSorter;
    }

    ///tests method sort()
    void testBubbleSort()
    {
        srand(time(NULL));
        int size = 5;
        double *array = new double[size];

        for (int i = 0; i < size; i++)
            array[i] = rand() % 1000;;

        Sorter *bubbleSorter = new BubbleSorter(array, size);
        bubbleSorter->sort();

        double *sortedArray = bubbleSorter->returnArray();
        for (int i = 1; i < size; i++)
        {
            QVERIFY(sortedArray[i] >= sortedArray[i - 1]);
        }

        delete[] sortedArray;
        delete bubbleSorter;
    }

    void testInsertSort()
    {
        srand(time(NULL));
        int size = 5;
        double *array = new double[size];

        for (int i = 0; i < size; i++)
            array[i] = rand() % 1000;;

        Sorter *insertSorter = new InsertSorter(array, size);
        insertSorter->sort();

        double *sortedArray = insertSorter->returnArray();
        for (int i = 1; i < size; i++)
        {
            QVERIFY(sortedArray[i] >= sortedArray[i - 1]);
        }

        delete[] sortedArray;
        delete insertSorter;
    }

    void testQuickSort()
    {
        srand(time(NULL));
        int size = 5;
        double *array = new double[size];

        for (int i = 0; i < size; i++)
            array[i] = rand() % 1000;;

        Sorter *qSorter = new QSorter(array, size);
        qSorter->sort();

        double *sortedArray = qSorter->returnArray();
        for (int i = 1; i < size; i++)
        {
            QVERIFY(sortedArray[i] >= sortedArray[i - 1]);
        }

        delete[] sortedArray;
        delete qSorter;
    }
};


