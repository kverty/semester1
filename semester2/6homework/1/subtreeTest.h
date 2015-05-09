#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "subtree.h"
#include "subtreeNumber.h"
#include "subtreeOperation.h"

class SubtreeTest : public QObject
{
    Q_OBJECT
public:
    explicit SubtreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testNumberSubtree()
    {
        Subtree *subtree = new NumberSubtree(42);
        QVERIFY(subtree->count() == 42);

        delete subtree;
    }

    void testOperationSubtreeWithTwoNumbers()
    {
        Subtree *subtree1 = new NumberSubtree(42);
        Subtree *subtree2 = new NumberSubtree(20);
        Subtree *subtreePlus = new OperationSubtree(subtree1, '+', subtree2);
        Subtree *subtreeMult = new OperationSubtree(subtree1, '*', subtree2);
        Subtree *subtreeMinus = new OperationSubtree(subtree1, '-', subtree2);
        Subtree *subtreeDivide = new OperationSubtree(subtree1, '/', subtree2);
        QVERIFY(subtreePlus->count() == 62);
        QVERIFY(subtreeMult->count() == 840);
        QVERIFY(subtreeMinus->count() == 22);
        QVERIFY(subtreeDivide->count() == 2);
    }

    void testOperationSubtree()
    {
        Subtree *subtree1 = new NumberSubtree(42);
        Subtree *subtree2 = new NumberSubtree(20);
        Subtree *subtree3 = new NumberSubtree(60);
        Subtree *subtreePlus = new OperationSubtree(subtree1, '+', subtree2);
        Subtree *subtreeMult = new OperationSubtree(subtreePlus, '*', subtree3);

        QVERIFY(subtreeMult->count() == 3720);
    }
};
