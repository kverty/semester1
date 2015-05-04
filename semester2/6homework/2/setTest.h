#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "set.h"

class SetTest : public QObject
{
   Q_OBJECT
public:
   explicit SetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testEmptySet()
    {
        Set<int> set;

        QVERIFY(set.getSize() == 0);
        QVERIFY(!set.wasAdded(42));
    }

    void testSetAddition()
    {
        Set<char> set;
        int rightLength = 0;

        for (char c = 'a'; c < 'z'; c++)
        {
            rightLength++;
            set.addValue(c);
            QVERIFY(set.getSize() == rightLength);
            QVERIFY(set.wasAdded(c));
        }
    }

    /// tests deletion if there is this value
    void testGoodDeletion()
    {
        Set<char> set;
        char c1 = 'a';
        char c2 = 'a';

        set.addValue(c1);
        QVERIFY(set.wasAdded(c1));
        QVERIFY(set.wasAdded(c2));

        set.deleteValue(c2);
        QVERIFY(!set.wasAdded(c1));
        QVERIFY(set.getSize() == 0);
    }

    /// tests deletion if there is no such value
    void testBadDeletion()
    {
        Set<int> set;
        int x = 42;

        for (int i = 0; i < 10; i++)
            set.addValue(i);

        QVERIFY(!set.wasAdded(x));
        set.deleteValue(x);
        QVERIFY(set.getSize() == 10);
    }

    /// one of the sets is empty
    void testUnionWithEmpty()
    {
        Set<int> set1;
        Set<int> set2;

        for (int i = 0; i < 10; i++)
            set1.addValue(i);

        QVERIFY(set1.unite(set2).getSize() == 10);
        QVERIFY(set2.unite(set1).getSize() == 10);
    }

    void testUnion()
    {
        Set<int> set1;
        Set<int> set2;

        for (int i = 0; i < 10; i++)
            set1.addValue(i);

        for (int i = 0; i < 15; i++)
            set2.addValue(i);

        QVERIFY(set1.unite(set2).getSize() == 15);
        QVERIFY(set2.unite(set1).getSize() == 15);
    }

    /// one of the sets is empty
    void testIntersectionWithEmpty()
    {
        Set<int> set1;
        Set<int> set2;

        for (int i = 0; i < 10; i++)
            set1.addValue(i);

        QVERIFY(set1.intersect(set2).getSize() == 0);
        QVERIFY(set2.intersect(set1).getSize() == 0);
    }

    void testIntersection()
    {
        Set<int> set1;
        Set<int> set2;

        for (int i = 0; i < 10; i++)
            set1.addValue(i);

        for (int i = 0; i < 15; i++)
            set2.addValue(i);

        QVERIFY(set1.intersect(set2).getSize() == 10);
        QVERIFY(set2.intersect(set1).getSize() == 10);
    }
};
