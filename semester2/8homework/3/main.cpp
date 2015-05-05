#include "xsandos.h"
#include <QApplication>

/// size of the field
const int size = 5;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XsAndOs w(size);
    w.show();

    return a.exec();
}
