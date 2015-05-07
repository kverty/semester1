#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "vector.h"

class VectorTest : public QObject
{
   Q_OBJECT
public:
   explicit VectorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///test for constructors and isZero()
    void testConstructor()
    {
        Vector<double> vector1;
        QVERIFY(vector1.isZero());

        Vector<int> vector2(3);
        QVERIFY(vector2.isZero());

        double *coordinates = new double[4];

        for (int i = 0; i < 4; i++)
            coordinates[i] = i;

        Vector<double> vector3(4, coordinates);
        QVERIFY(!vector3.isZero());

        delete[] coordinates;
    }

    ///test for copy-constructor and operator ==
    void testCopyConstructor()
    {
        Vector<double> vector1;
        Vector<double> vector2(4);

        QVERIFY(!(vector1 == vector2));

        double *coordinates = new double[4];

        for (int i = 0; i < 4; i++)
            coordinates[i] = i;

        Vector<double> vector3(4, coordinates);
        Vector<double> vector4(vector3);

        QVERIFY(!(vector3 == vector2));
        QVERIFY(vector3 == vector4);

        delete[] coordinates;
    }

    ///test for operator - and isZero()
    void testMinus()
    {
        Vector<int> vector1(3);
        Vector<int> vector2(4);

        QVERIFY_EXCEPTION_THROWN(
        {
            Vector<int> result;
            result = vector1 - vector2;
        },
        DifferentDimensionException);


        int *coordinates1 = new int[4];
        int *coordinates2 = new int[4];
        int *ansCoordinates = new int[4];

        for (int i = 0; i < 4; i++)
        {
            coordinates1[i] = i;
            coordinates2[i] = i * i;
            ansCoordinates[i] = i - i * i;
        }

        Vector<int> vector3(4, coordinates1);
        Vector<int> vector4(4, coordinates2);
        Vector<int> vector5(vector3);
        Vector<int> result;
        Vector<int> answer(4, ansCoordinates);
        try
        {
            result = vector3 - vector4;
            QVERIFY(result == answer);
            result = vector3 - vector2;
            QVERIFY(result == vector3);
            result = vector3 - vector5;
            QVERIFY(result == vector2);
        }

        catch(DifferentDimensionException)
        {
            QVERIFY(false);
        }

        delete[] coordinates1;
        delete[] coordinates2;
    }

    /// test for operator +
    void testPlus()
    {
        Vector<double> vector1(3);
        Vector<double> vector2(4);

        QVERIFY_EXCEPTION_THROWN(
        {
            Vector<double> result;
            result = vector1 - vector2;
        },
        DifferentDimensionException);


        double *coordinates1 = new double[4];
        double *coordinates2 = new double[4];
        double *ansCoordinates = new double[4];

        for (int i = 0; i < 4; i++)
        {
            coordinates1[i] = i;
            coordinates2[i] = i * i;
            ansCoordinates[i] = i + i * i;
        }

        Vector<double> vector3(4, coordinates1);
        Vector<double> vector4(4, coordinates2);
        Vector<double> result;
        Vector<double> answer(4, ansCoordinates);
        try
        {
            result = vector3 + vector4;
            QVERIFY(result == answer);
            result = vector3 + vector2;
            QVERIFY(result == vector3);
        }

        catch(DifferentDimensionException)
        {
            QVERIFY(false);
        }

        delete[] coordinates1;
        delete[] coordinates2;
    }

    ///test operator vector * T = vector
    void testMultWithScalar()
    {
        int *coordinates1 = new int[4];

        for (int i = 0; i < 4; i++)
            coordinates1[i] = i;

        Vector<int> vector2(4);
        Vector<int> vector3(4, coordinates1);
        Vector<int> result;
        Vector<int> answer;
        answer = vector3 + vector3;

        result = vector3 * 0;
        QVERIFY(result == vector2);
        result = vector3 * (-1) + vector3;
        QVERIFY(result == vector2);
        result = vector3 * 2;

        delete[] coordinates1;
    }

    ///test operator vector * vector = T
    void testMultWithVector()
    {
        Vector<int> vector1(5);
        Vector<int> vector2(4);

        QVERIFY_EXCEPTION_THROWN(int result = vector1 * vector2, DifferentDimensionException);

        int *coordinates1 = new int[4];

        for (int i = 0; i < 4; i++)
            coordinates1[i] = i;

        Vector<int> vector3(4, coordinates1);

        int *coordinates2 = new int[4];
        int answer = 0;

        for (int i = 0; i < 4; i++)
        {
            coordinates2[i] = i * i;
            answer += i * i * i;
        }

        Vector<int> vector4(4, coordinates2);
        int result;
        try
        {
            result = vector2 * vector3;
            QVERIFY(result == 0);
            result = vector3 * vector4;
            QVERIFY(result == answer);
        }

        catch(DifferentDimensionException)
        {
            QVERIFY(false);
        }

        delete[] coordinates1;
        delete[] coordinates2;
    }
};
