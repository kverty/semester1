#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "comparableList.h"
#include "listComparator.h"
#include <time.h>

class ComparableWithSizeTest : public QObject
{
   Q_OBJECT
public:
   explicit ComparableWithSizeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///test for constructor and empty List
    void testDegenerateComparableList()
    {
        srand(time(NULL));
        ComparableList *list = new ComparableList();
        QVERIFY(list->length() == 0);
        QVERIFY(!list->deleteElement(rand() % testSize));

        delete list;
    }

    /// test for method length() and addElement()
    void testLengthSimpleList()
    {
        ComparableList *list = new ComparableList();
        for (int i = 0; i < testSize; i++)
        {
            list->addElement(i);
            QVERIFY(list->length() == i + 1);
        }

        delete list;
    }

    /// tests for addElement() and deleteElement(), where we want to delete element we have added to the List
    void testForGoodRemovalSimpleList()
    {
        int rightLength = 0;
        ComparableList *list = new ComparableList();

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

        delete list;
    }

    /// test for addElement() and deleteElement() where there is no element we want to delete
    void testForBadRemovalSimpleList()
    {
        srand(time(NULL));
        int rightLength = 0;
        ComparableList *list = new ComparableList();

        for (int i = 0; i < testSize; i++)
        {
            list->addElement(i);
            rightLength++;
        }

        QVERIFY(!list->deleteElement(rand() % testSize + testSize));
        QVERIFY(list->length() == rightLength);

        delete list;
    }

    ///test for compareTo method
    void testForCompareTo()
    {
        ComparableList *list1 = new ComparableList();
        for (int i = 0; i < testSize; i++)
            list1->addElement(i);

        ComparableList *list2 = new ComparableList();
        for (int i = 0; i < testSize - 1; i++)
             list2->addElement(i);

        ComparableList *list3 = new ComparableList();
        for (int i = 0; i < testSize; i++)
             list3->addElement(i);

        QVERIFY(list2->compareTo(list1) == -1);
        QVERIFY(list3->compareTo(list1) == 0);
        QVERIFY(list1->compareTo(list1) == 0);
        QVERIFY(list1->compareTo(list2) == 1);

        delete list3;
        delete list2;
        delete list1;
    }

private:
    int testSize = 5;
};
