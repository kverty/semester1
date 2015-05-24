#include "bashQuotes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BashQuotes w;
    w.show();

    return a.exec();
}
