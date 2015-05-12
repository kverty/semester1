#include "sharedPointer.h"
#include "sharedPointerTest.h"

int main()
{
    SharedPtrTest test;
    QTest::qExec(&test);
}
