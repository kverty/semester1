#include "servertankwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerTankWindow w;
    w.show();

    return a.exec();
}
