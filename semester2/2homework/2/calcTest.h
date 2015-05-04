#include <QtCore/QObject>
#include <QtTest/QTest>

#include "expressions.h"
#include "calculator.h"
#include <time.h>

class CalcTest : public QObject
{
   Q_OBJECT
public:
   explicit CalcTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///tests for different operations
    void testAddition()
    {
        Calculator *calc = new Calculator("1+4", 3);
        QVERIFY(calc->countUp() == 5);

        delete calc;
    }

    ///test for multiplication
    void testMultiplication()
    {
        Calculator *calc = new Calculator("3*4", 3);
        QVERIFY(calc->countUp() == 12);

        delete calc;
    }

    ///test for division
    void testDivision()
    {
        Calculator *calc = new Calculator("56/9", 4);
        QVERIFY(calc->countUp() == 6);

        delete calc;
    }

    ///test for substraction
    void testSubstraction()
    {
        Calculator *calc = new Calculator("5-9", 3);
        QVERIFY(calc->countUp() == -4);

        delete calc;
    }

    ///test for brackets
    void testWithBrackets()
    {
        Calculator *calc = new Calculator("3*(2+1)", 7);
        QVERIFY(calc->countUp() == 9);

        delete calc;
    }
};
