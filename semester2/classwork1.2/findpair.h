#ifndef FINDPAIR_H
#define FINDPAIR_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include "myButton.h"

namespace Ui {
class FindPair;
}

class FindPair : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindPair(int size, QWidget *parent = 0);
    ~FindPair();

private:
    Ui::FindPair *ui;
    MyButton *field;
    int size;
};

#endif // FINDPAIR_H
