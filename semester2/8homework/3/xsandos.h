#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QObject>
#include <QLineEdit>
#include <QMessageBox>

#include <QtCore/QObject>
#include <QtTest/QTest>

/// tests for game rules
/// it is here, not in the separate header, because i need to write that this class is friend of others
class GameTest : public QObject
{
    Q_OBJECT
public:
    explicit GameTest(int argc, char *argv[], QObject *parent = 0) : argc(argc), argv(argv), QObject(parent) {}

private slots:
    void winningTest();
    void notWinningTest();
    void noLineTest();

private:
    int argc;
    char **argv;
};


namespace Ui {
class XsAndOs;
}

/// class for button with some special slots and signals
class MyButton : public QObject
{
    Q_OBJECT

public:
    MyButton(QPushButton *pushButton) : pushButton(pushButton), mWasClicked(false), turn(0) {}
    MyButton() : pushButton(new QPushButton(" ")), mWasClicked(false), turn(0) {}
    /// returns mWasClicked
    bool wasClicked()
    {
        return mWasClicked;
    }
    QString symbol()
    {
        return pushButton->text();
    }

    void finishGame()
    {
        pushButton->setDisabled(false);
        pushButton->disconnect(pushButton, SIGNAL(clicked()), this, SLOT(changeSymbol()));
    }

    friend GameTest;

public slots:
    /// works when we click on button, changes symbol written on the button
    void changeSymbol();
    /// increses turn when we click button first time, and counts if somebody won
    void nextTurn();

signals:
    /// emits when button we click hasn't been clicked yet
    void clickedCorrectly();

private:
    QPushButton *pushButton;
    bool mWasClicked;
    /// which turn is it
    int turn;
};

class XsAndOs : public QMainWindow
{
    Q_OBJECT

public:
    explicit XsAndOs(bool isTest, int size, QWidget *parent = 0);
    ~XsAndOs();
    /// writes who win
    void finishGame();

    friend GameTest;

private:
    Ui::XsAndOs *ui;
    /// size of field
    int size;
    MyButton* **field;
    QLineEdit *whoseTurn;
    /// number of symbols in the row you should get to win
    int symbolsInTheRow;

public slots:
    /// whites whose turn is it
    void changeWhoseTurn();
    /// checkes if somebody wins
    void check();
};
