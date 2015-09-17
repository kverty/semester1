#include "queue.h"
#include "queueTest.h"
#include <iostream>

using namespace std;

int main()
{
    QueueTest test;
    QTest::qExec(&test);
    int testSize = 5;

    srand(time(NULL));
    int number = rand() % testSize;
    Queue<int> *queue = new Queue<int>();

    queue->enqueue(number, [](int val) -> int{return val;});
    int x = queue->dequeue([](int val) -> int{return val;});
    cout << x << endl;

    return 0;
}
