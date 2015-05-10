#ifndef XSANDOS_H
#define XSANDOS_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QObject>
#include <QLineEdit>

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
    explicit XsAndOs(int size, QWidget *parent = 0);
    ~XsAndOs();
    /// writes who win
    void finishGame();

private:
    Ui::XsAndOs *ui;
    /// size of field
    int size;
    MyButton* **field;
    //QLineEdit *rules;
    QLineEdit *whoseTurn;
    /// number of symbols in the row ypu should get to win
    int symbolsInTheRow;

public slots:
    /// whites whose turn is it
    void changeWhoseTurn();
    /// checkes if somebody wins
    void check();
};

#endif // XSANDOS_H
