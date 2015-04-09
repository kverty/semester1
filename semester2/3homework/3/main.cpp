#include <iostream>
#include "comparableList.h"
#include "listComparator.h"
#include "comparableListTest.h"
#include "sortedSet.h"
#include "sortedSetTest.h"
using namespace std;

int main()
{
    ComparableWithSizeTest test1;
    QTest::qExec(&test1);

    SortedSetTest test2;
    QTest::qExec(&test2);
}

