#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "tree.h"
#include <time.h>
#include "iterator.h"

class IteratorTest : public QObject
{
   Q_OBJECT
public:
   explicit IteratorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    /// simple test
    void initTest()
    {
        Tree *tree = new Tree();
        tree->addValue(5);
        TreeIterator iterator(tree);
        QVERIFY(!iterator.isLast());
        QVERIFY(iterator.next() == 5);
    }
    /// time ran out
};
