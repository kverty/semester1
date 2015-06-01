#include "xsandos.h"
#include <QApplication>

/// size of the field
const int size = 3;

int main(int argc, char *argv[])
{
    GameTest test(argc, argv);
    QTest::qExec(&test);

    QApplication a(argc, argv);
    XsAndOs w(false, size);
    w.show();

    return a.exec();
}
