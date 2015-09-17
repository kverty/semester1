#include "findpair.h"
#include <QApplication>
#include "buttonTest.h"

/// size of the field, should be even
const int size = 8;
/// number of different cards that can be on the field
const int numberOfCards = 5;

int main(int argc, char *argv[])
{
    ButtonTest test;
    QTest::qExec(&test);

    QApplication a(argc, argv);
    FindPair w(size, numberOfCards);
    w.show();

    return a.exec();
}
