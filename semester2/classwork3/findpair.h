#pragma once

#include <QtWidgets>
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QLineEdit>
#include "myButton.h"

/// creates array with each number having its pair
int *makeArray(int size, int numberOfCards);
/// game find pair
namespace Ui {
class FindPair;
}

class FindPair : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindPair(int size, int numberOfCards, QWidget *parent = 0);
    ~FindPair();
    ///2 drawing methods
    void draw();
    void redraw();

private:
    Ui::FindPair *ui;
    MyButton* *field;
    QGridLayout *buttons;
    int size;
    MyButton *clickedOne;
    int moves;
    QLineEdit *movesLine;

public slots:
    /// works when button is clicked
    void nextButton();
};
