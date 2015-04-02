#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "comparableList.h"
#include "listComparator.h"
#include "sortedSet.h"
#include <time.h>

class SortedSetTest : public QObject
{
   Q_OBJECT
public:
   explicit SortedSetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///test for constructor and empty SortedSet
    void testDegenerateSortedSet()
    {
        srand(time(NULL));
        SortedSet *set = new SortedSet();
        ComparableList *list = new ComparableList();
        for (int i = 0; i < testSize; i++)
            list->addElement(i);

        QVERIFY(set->length() == 0);
        QVERIFY(!set->deleteElement(list));
    }

    /// test for method length() and addElement()
    void testLengthSimpleList()
    {
        ComparableList *newList = new ComparableList();
        for (int i = 0; i < testSize; i++)
            newList->addElement(i);

        SortedSet *set = new SortedSet();
        for (int i = 0; i < testSize; i++)
        {
            set->addElement(newList);
            QVERIFY(set->length() == i + 1);
        }
    }

    /// tests for addElement() and deleteElement(), where we want to delete element we have added to the Set
    void testForGoodRemovalSimpleList()
    {
        int rightLength = 0;
        SortedSet *set = new SortedSet();

        for (int i = 0; i < testSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ComparableList *newList = new ComparableList();
                for (int k = 0; k < i; k++)
                    newList->addElement(k);

                set->addElement(newList);
                rightLength++;
            }
        }

        for (int i = testSize - 1; i > 0; i--)
        {
            ComparableList *newList = new ComparableList();
            for (int k = 0; k < i; k++)
                newList->addElement(k);

            QVERIFY(set->deleteElement(newList));
            rightLength -= i;
            QVERIFY(set->length() == rightLength);
        }
    }

    /// test for addElement() and deleteElement() where there is no element we want to delete
    void testForBadRemovalSimpleList()
    {
        srand(time(NULL));
        int rightLength = 0;
        SortedSet *set = new SortedSet();

        for (int i = 0; i < testSize; i++)
        {
            ComparableList *newList = new ComparableList();
            for (int k = 0; k < i; k++)
                newList->addElement(k);

            set->addElement(newList);
            rightLength++;
        }

        ComparableList *newList = new ComparableList();
        int length = rand() % testSize + testSize;
        for (int k = 0; k < length; k++)
            newList->addElement(k);

        QVERIFY(!set->deleteElement(newList));
        QVERIFY(set->length() == rightLength);
    }

private:
    int testSize = 5;
};
