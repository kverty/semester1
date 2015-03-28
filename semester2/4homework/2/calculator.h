#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "simpleCalculator.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void onFirstArgumentValueChanged(int arg1);
    void onSecondArgumentValueChanged(int arg2);
    void onOperationCurrentIndexChanged(int index);

private:
    Ui::Calculator *ui;
    SimpleCalculator *calculator;
};

#endif // CALCULATOR_H
