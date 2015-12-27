#include "clienttankwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientTankWindow w;
    w.show();

    return a.exec();
}
