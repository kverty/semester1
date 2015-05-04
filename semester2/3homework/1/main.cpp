#include "sort.h"
#include "qsort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "sortTest.h"
#include <iostream>

using namespace std;

int main()
{
    SorterTest test;
    QTest::qExec(&test);
}

