#include "vector.h"
#include <iostream>
#include "vectorTest.h"

using namespace std;

int main()
{
    VectorTest test;
    QTest::qExec(&test);

    return 0;
}
