#include "xsandos.h"
/// Os made straight line and chack() finds it
void GameTest::winningTest()
{
    QApplication a(argc, argv);
    XsAndOs w(true, 3);
    w.field[0][0]->pushButton->setText("O");
    w.field[1][0]->pushButton->setText("O");
    w.field[2][0]->pushButton->setText("O");
    w.whoseTurn->setText("X turn");
    w.check();
    QVERIFY(w.whoseTurn->text() == "O win");
}

/// because it wasn't Os turn => they couldn't have won this turn, so check() doesn't see this line
void GameTest::notWinningTest()
{
    QApplication a(argc, argv);
    XsAndOs w(true, 3);
    w.field[0][0]->pushButton->setText("O");
    w.field[1][0]->pushButton->setText("O");
    w.field[2][0]->pushButton->setText("O");
    w.whoseTurn->setText("O turn");
    w.check();
    QVERIFY(w.whoseTurn->text() != "O win");
}

/// just there is no line
void GameTest::noLineTest()
{
    QApplication a(argc, argv);
    XsAndOs w(true, 3);
    w.field[0][0]->pushButton->setText("X");
    w.field[1][0]->pushButton->setText("O");
    w.field[2][0]->pushButton->setText("X");
    w.field[0][1]->pushButton->setText("O");
    w.field[1][1]->pushButton->setText("O");
    w.field[2][1]->pushButton->setText("X");
    w.field[0][2]->pushButton->setText("X");
    w.field[1][2]->pushButton->setText("X");
    w.field[2][2]->pushButton->setText("O");
    w.whoseTurn->setText("X turn");
    w.check();
    QVERIFY(w.whoseTurn->text() != "O win");
    w.whoseTurn->setText("O turn");
    w.check();
    QVERIFY(w.whoseTurn->text() != "X win");
}
