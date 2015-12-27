#include "tanksgame.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    w.setCentralWidget(new TanksGame);
    w.setMinimumSize(QSize(600, 500));
    w.show();

    return a.exec();
}
