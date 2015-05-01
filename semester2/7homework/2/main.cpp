#include <iostream>
#include "uniqueList.h"
#include "listTest.h"
#include "list.h"

using namespace std;

int main()
{
    ListTest test;
    QTest::qExec(&test);

    return 0;
}

