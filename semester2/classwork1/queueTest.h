#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "queue.h"
#include <time.h>
#include <algorithm>


class QueueTest : public QObject
{
   Q_OBJECT
public:
   explicit QueueTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///tests templates and functions
    /// and empty queue
    void testEmptyQueue()
    {
        Queue<int> *intQueue = new Queue<int>();
        intQueue->enqueue(2, [](int val) -> int{return val;});
        Queue<double> *doubleQueue = new Queue<double>();
        doubleQueue->enqueue(2, [](double val) -> int{return 0;});
    }

    ///tests enqueue() and dequeue()
    void testAddAndDeleteFromTheQueue()
    {
        srand(time(NULL));
        int number = rand() % testSize;
        Queue<int> *queue = new Queue<int>();
        queue->enqueue(number, [](int val) -> int{return val;});
        int x = queue->dequeue([](int val) -> int{return val;});
        QVERIFY(x == number);
    }
private:
    int testSize;
};
