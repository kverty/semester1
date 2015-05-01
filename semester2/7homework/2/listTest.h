#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "list.h"
#include "uniqueList.h"
#include <time.h>

class ListTest : public QObject
{
   Q_OBJECT
public:
   explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///test for constructor and empty List
    void testDegenerateUniqueList()
    {
        srand(time(NULL));
        List *list = new UniqueList();
        bool excWorking = false;

        QVERIFY(list->length() == 0);
        try
        {
            list->deleteElement(rand() % testSize);
        }
        catch (ElementNotFoundExc const &)
        {
            excWorking = true;
        }

        QVERIFY(excWorking);

        delete list;
    }

    /// test for method length() and addElement()
    void testLengthUniqueList()
    {
        List *list = new UniqueList();
        bool excWorking = false;

        try
        {
            for (int i = 0; i < testSize; i++)
            {
                list->addElement(i);
                QVERIFY(list->length() == i + 1);
            }
        }

        catch(DublicateExc const &)
        {
            excWorking = true;
        }

        QVERIFY(!excWorking);

        delete list;
    }

    /// tests for addElement() and deleteElement(), where we want to delete element we have added to the List
    void testForGoodRemovalUniqueList()
    {
        int rightLength = 0;
        List *list = new UniqueList();
        try
        {
            for (int i = 0; i < testSize; i++)
            {
                list->addElement(i);
                rightLength++;
            }

            for (int i = testSize - 1; i > 0; i--)
            {
                list->deleteElement(i);
                rightLength--;
                QVERIFY(list->length() == rightLength);
            }
        }

        catch(DublicateExc)
        {
            QVERIFY(false);
        }

        catch(ElementNotFoundExc)
        {
            QVERIFY(false);
        }

        delete list;
    }

    /// test for addElement() and deleteElement() where there is no element we want to delete
    void testForBadRemovalUniqueList()
    {
        srand(time(NULL));
        int rightLength = 0;
        List *list = new UniqueList();
        try
        {
            for (int i = 0; i < testSize; i++)
            {
                list->addElement(i);
                rightLength++;
            }

            list->deleteElement(rand() % testSize + testSize);
            QVERIFY(list->length() == rightLength);
        }
        catch(DublicateExc)
        {
            QVERIFY(false);
        }

        catch(ElementNotFoundExc)
        {
            QVERIFY(true);
        }

        delete list;
    }

private:
    int testSize = 5;
};
