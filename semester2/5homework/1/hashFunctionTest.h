#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "hashFunction.h"
#include "hashFunctionPolynom.h"
#include "hashFunctionSquares.h"
#include "hashFunctionSum.h"
#include <time.h>

class HashFunctionTest : public QObject
{
   Q_OBJECT
public:
   explicit HashFunctionTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    /// tests for empty strings
    void testSumOfSquaresEmpty()
    {
        HashFunction *hash = new SquareHashFunction();
        QVERIFY(hash->count("", 20) == 0);
    }

    void testSumOfSquares()
    {
        HashFunction *hash = new SquareHashFunction();
        QVERIFY(hash->count("abc", 10) == 4);
    }

    void testPolynomEmpty()
    {
        HashFunction *hash = new PolynomHashFunction();
        QVERIFY(hash->count("", 20) == 0);
    }

    ///simple tests for different functions
    void testPolynom()
    {
        HashFunction *hash = new PolynomHashFunction();
        QVERIFY(hash->count("abc", 10) == 6);
    }

    void testSumEmpty()
    {
        HashFunction *hash = new PolynomHashFunction();
        QVERIFY(hash->count("", 20) == 0);
    }

    void testSum()
    {
        HashFunction *hash = new PolynomHashFunction();
        QVERIFY(hash->count("abc", 10) == 6);
    }
};
