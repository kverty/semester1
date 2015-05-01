#include "example.h"
#include "exampleTest.h"

int main()
{
    ExampleTest test;
    QTest::qExec(&test);
}
