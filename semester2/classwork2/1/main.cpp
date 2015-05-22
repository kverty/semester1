#include "tree.h"
#include "treeTest.h"
#include "iterator.h"
#include "iteratorTest.h"

int main()
{
    TreeTest test1;
    QTest::qExec(&test1);

    IteratorTest test2;
    QTest::qExec(&test2);
}
