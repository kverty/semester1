#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "stack.h"
#include "simpleStack.h"
#include "arrayStack.h"
#include <time.h>

class StackTest : public QObject
{
   Q_OBJECT
public:
   explicit StackTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    /// test for constructor and empty Stack
    void testDegenerateSimpleStack()
    {
        Stack *stack = new SimpleStack();
        QVERIFY(stack->mLength() == 0);
        QVERIFY(stack->pop() == nullptr);
    }

    void testDegenerateArrayStack()
    {
        Stack *stack = new ArrayStack();
        QVERIFY(stack->mLength() == 0);
        QVERIFY(stack->pop() == nullptr);
    }

    /// test for push() and mLength()
    void testLengthSimleStack()
    {
        Stack *stack = new SimpleStack();
        for (int i = 0; i < testSize; i++)
        {
            Token *token = new Token(i, number);
            stack->push(token);
            QVERIFY(stack->mLength() == i + 1);
        }
    }

    void testLengthArrayStack()
    {
        Stack *stack = new ArrayStack();
        for (int i = 0; i < testSize; i++)
        {
            Token *token = new Token(i, number);
            stack->push(token);
            QVERIFY(stack->mLength() == i + 1);
        }
    }

    /// test for pop()
    void testForGoodRemovalSimpleStack()
    {
        srand(time(NULL));
        Stack *stack = new SimpleStack();
        int *array = new int[testSize];

        for (int i = 0; i < testSize; i++)
        {
            array[i] = rand() % testSize;
            stack->push(new Token(array[i], number));
        }
        int rightLength = stack->mLength();

        for (int i = testSize - 1; i >= 0; i--)
        {
            QVERIFY(stack->pop()->number() == array[i]);
            rightLength--;
            QVERIFY(stack->mLength() == rightLength);
        }
    }

    void testForGoodRemovalArrayStack()
    {
        srand(time(NULL));
        Stack *stack = new ArrayStack();
        int *array = new int[testSize];

        for (int i = 0; i < testSize; i++)
        {
            array[i] = rand() % testSize;
            stack->push(new Token(array[i], number));
        }

        int rightLength = stack->mLength();

        for (int i = testSize - 1; i >= 0; i--)
        {
            QVERIFY(stack->pop()->number() == array[i]);
            rightLength--;
            QVERIFY(stack->mLength() == rightLength);
        }
    }


private:
    int testSize = 5;
};
