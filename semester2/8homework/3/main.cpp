#include "xsandos.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XsAndOs w(5);
    w.show();

    return a.exec();
}
