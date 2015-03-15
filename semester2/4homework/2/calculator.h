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
    void on_firstArgument_valueChanged(int arg1);
    void on_secondArgument_valueChanged(int arg2);
    void on_operation_currentIndexChanged(int index);

private:
    Ui::Calculator *ui;
    SimpleCalculator *calculator;
};

#endif // CALCULATOR_H
