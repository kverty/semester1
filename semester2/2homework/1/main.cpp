#include <iostream>
#include "doublelinkedList.h"
#include "simpleList.h"
#include "listTest.h"

using namespace std;

int main()
{
    ListTest test;
    QTest::qExec(&test);
    return 0;
}

