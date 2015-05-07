#include "findpair.h"
#include <QApplication>
#include "buttonTest.h"

const int size = 6;
/// size of the field, should be even

int main(int argc, char *argv[])
{
    ButtonTest test;
    QTest::qExec(&test);

    QApplication a(argc, argv);
    FindPair w(size);
    w.show();

    return a.exec();
}
