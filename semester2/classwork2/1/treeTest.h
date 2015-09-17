#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "tree.h"
#include <time.h>

class TreeTest : public QObject
{
   Q_OBJECT
public:
   explicit TreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void initTest()
    {
        srand(time(NULL));
        Tree tree;
        QVERIFY(!tree.contains(rand() % 100));
    }

    void simpleAdditionTest()
    {
        Tree tree;
        tree.addValue(3.5);
        QVERIFY(tree.contains(3.5));
    }

    void manyElementsAdditionTest()
    {
        Tree tree;
        for (int i = 0; i < 10; i++)
            tree.addValue(i);

        for (int i = 0; i < 10; i++)
             QVERIFY(tree.contains(i));
    }

    void simpleDeletionTest()
    {
        Tree tree;
        tree.addValue('a');
        QVERIFY_EXCEPTION_THROWN(tree.deleteValue('b');, ElementNotFoundException);
        try
        {
            tree.deleteValue('a');
            QVERIFY(!tree.contains('a'));
        }
        catch(ElementNotFoundException)
        {
            QVERIFY(false);
        }
    }

    void multipleDeletionTest()
    {
        Tree tree;
        for (int i = 0; i < 20; i++)
            tree.addValue(i);

        try
        {
            for (int i = 0; i < 20; i++)
                tree.deleteValue(i);
        }
        catch(ElementNotFoundException)
        {
            QVERIFY(false);
        }

        for (int i = 0; i < 20; i++)
            QVERIFY(!tree.contains(i));
    }
};
