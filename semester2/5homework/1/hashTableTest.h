#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "hashTable.h"
#include "hashFunction.h"
#include "hashFunctionPolynom.h"
#include "hashFunctionSquares.h"
#include "hashFunctionSum.h"

#include <time.h>

class HashTableTest : public QObject
{
   Q_OBJECT
public:
   explicit HashTableTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    /// degenerative test with empty table
    void testEmptyTable()
    {
        HashFunction *hash = new SquareHashFunction();
        HashTable* table = new HashTable();
        table->newHash(hash);
        QVERIFY(!table->wasAdded("a"));
        QVERIFY(!table->deleteValue("b"));
    }

    ///test with only one element
    void testUnoTable()
    {
        HashFunction *hash = new SumHashFunction();
        HashTable* table = new HashTable();
        table->newHash(hash);
        table->addValue("c");
        QVERIFY(table->wasAdded("c"));
        QVERIFY(table->deleteValue("c"));
        QVERIFY(!table->wasAdded("c"));
    }

    /// test for newHash() if anything is lost
    void testNewHash()
    {
        HashFunction *hash = new SumHashFunction();
        HashTable* table = new HashTable();
        table->newHash(hash);
        table->addValue("az");
        table->addValue("by");
        table->addValue("cx");
        table->addValue("dw");
        table->addValue("ev");
        table->addValue("fu");
        table->addValue("gf");
        table->addValue("hv");
        table->addValue("lf");
        table->addValue("op");
        table->addValue("rf");

        HashFunction *newHash = new SquareHashFunction();
        table->newHash(newHash);
        QVERIFY(table->wasAdded("az"));
        QVERIFY(table->wasAdded("cx"));
        QVERIFY(table->wasAdded("dw"));
        QVERIFY(table->wasAdded("fu"));
        QVERIFY(table->wasAdded("lf"));
        QVERIFY(table->wasAdded("op"));
    }
};
