#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "simpleList.h"
#include <string>

class ListTest : public QObject
{
   Q_OBJECT
public:
   explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///test for constructor and empty List
    void testDegenerateSimpleList()
    {
        SimpleList *list = new SimpleList();
        QVERIFY(list->length() == 0);
        QVERIFY(!list->deleteElement("ab"));
        QVERIFY(!list->wasAdded("ab"));
        QVERIFY(list->pop() == "");

        delete list;
    }

    ///test for method pop() and addElement()
    void testPop()
    {
        SimpleList *list = new SimpleList();
        list->addElement("ab");
        list->addElement("bc");
        QVERIFY(list->pop() == "bc");
        QVERIFY(list->pop() == "ab");
    }

    /// test for method length() and addElement()
    void testLengthSimpleList()
    {
        SimpleList *list = new SimpleList();
        for (int i = 0; i < testSize; i++)
        {
            list->addElement("a");
            QVERIFY(list->wasAdded("a"));
            QVERIFY(list->length() == i + 1);
        }

        delete list;
    }

    /// tests for addElement(), wasAdded() and deleteElement()
    void testForGoodRemovalSimpleList()
    {
        int rightLength = 0;
        SimpleList *list = new SimpleList();

        for (int i = 0; i < testSize; i++)
        {
            list->addElement("ab");
            rightLength++;
        }

        for (int i = 0; i < testSize; i++)
        {
            list->addElement("aba");
            rightLength++;
        }

        list->addElement("aa");
        rightLength++;

        QVERIFY(!list->wasAdded("lol"));
        QVERIFY(!list->deleteElement("lol"));
        QVERIFY(list->length() == rightLength);

        QVERIFY(list->wasAdded("ab"));
        QVERIFY(list->deleteElement("ab"));
        rightLength -= testSize;
        QVERIFY(list->length() == rightLength);

        QVERIFY(list->wasAdded("aa"));
        QVERIFY(list->deleteElement("aa"));
        rightLength --;
        QVERIFY(list->length() == rightLength);

        delete list;
    }

private:
    int testSize = 5;
};
