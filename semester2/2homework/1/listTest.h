#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "list.h"
#include "simpleList.h"
#include "doublelinkedList.h"
#include <time.h>

class ListTest : public QObject
{
   Q_OBJECT
public:
   explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testDegenerateSimpleList()
    {
        List *list = new SimpleList();
        QVERIFY(list->length() == 0);
    }

    void testDegenerateDoubleList()
    {
        List *list = new DoubleLinkedList();
        QVERIFY(list->length() == 0);
    }

    void testLengthSimpleList()
    {
        List *list = new SimpleList();
        for (int i = 0; i < testSize; i++)
        {
            list->addElement(i);
            QVERIFY(list->length() == i + 1);
        }
    }

    void testLengthDoubleList()
    {
        List *list = new DoubleLinkedList();
        for (int i = 0; i < testSize; i++)
        {
            list->addElement(i);
            QVERIFY(list->length() == i + 1);
        }
    }

    void testForGoodRemovalSimpleList()
    {
        int rightLength = 0;
        List *list = new SimpleList();

        for (int i = 0; i < testSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                list->addElement(i);
                rightLength++;
            }
        }

        for (int i = testSize - 1; i > 0; i--)
        {
            QVERIFY(list->deleteElement(i));
            rightLength -= i;
            QVERIFY(list->length() == rightLength);
        }
    }

    void testForBadRemovalSimpleList()
    {
        srand(time(NULL));
        int rightLength = 0;
        List *list = new SimpleList();

        for (int i = 0; i < testSize; i++)
        {
            list->addElement(i);
            rightLength++;
        }

        QVERIFY(!list->deleteElement(rand() % testSize + testSize));
        QVERIFY(list->length() == rightLength);
    }

    void testForGoodRemovalDoubleList()
    {
        int rightLength = 0;
        List *list = new DoubleLinkedList();

        for (int i = 0; i < testSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                list->addElement(i);
                rightLength++;
            }
        }

        for (int i = testSize - 1; i > 0; i--)
        {
            QVERIFY(list->deleteElement(i));
            rightLength -= i;
            QVERIFY(list->length() == rightLength);
        }
    }

    void testForBadRemovalDoubleList()
    {
        srand(time(NULL));
        int rightLength = 0;
        List *list = new DoubleLinkedList();

        for (int i = 0; i < testSize; i++)
        {
            list->addElement(i);
            rightLength++;
        }

        QVERIFY(!list->deleteElement(rand() % testSize + testSize));
        QVERIFY(list->length() == rightLength);
    }

private:
    int testSize = 5;
};
