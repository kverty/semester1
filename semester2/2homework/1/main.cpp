#include <iostream>
#include "doublelinkedList.h"
#include "simpleList.h"
#include "listTest.h"

using namespace std;

int main()
{
    ListTest test;
    QTest::qExec(&test);

    int testSize = 5;
    int rightLength = 0;
    List *list = new DoubleLinkedList();

    for (int i = 0; i < testSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            list->addElement(i);
            rightLength++;
        }
    }

    for (int i = 1; i < testSize; i++)
    {
        list->deleteElement(i);
        rightLength -= i;
        cout << endl << list->length() << " " << rightLength << endl;
        list->print();
    }
    return 0;
}

