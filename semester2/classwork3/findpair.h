#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include "myButton.h"

int *makeArray(int size, int numberOfCards);

namespace Ui {
class FindPair;
}

class FindPair : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindPair(int size, int numberOfCards, QWidget *parent = 0);
    ~FindPair();

private:
    Ui::FindPair *ui;
    MyButton* *field;
    int size;
    MyButton *clickedOne;

public slots:
    void nextButton();
};
