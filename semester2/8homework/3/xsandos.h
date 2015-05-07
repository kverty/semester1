#ifndef XSANDOS_H
#define XSANDOS_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QObject>

namespace Ui {
class XsAndOs;
}

/// class for button with some special slots and signals
class MyButton : public QObject
{
    Q_OBJECT

public:
    MyButton(QPushButton *pushButton) : pushButton(pushButton), wasClicked(false), turn(0) {}
public slots:
    /// works when we click on button, changes symbol written on the button
    void changeSymbol();
    /// increses turn when we click button first time
    void nextTurn();

signals:
    /// emits when button we click hasn't been clicked yet
    void clickedCorrectly();

private:
    bool wasClicked;
    QPushButton *pushButton;
    /// which turn is it
    int turn;
};

class XsAndOs : public QMainWindow
{
    Q_OBJECT

public:
    explicit XsAndOs(int size, QWidget *parent = 0);
    ~XsAndOs();

private:
    Ui::XsAndOs *ui;
    /// size of field
    int size;
};

#endif // XSANDOS_H
