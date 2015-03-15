#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    calculator = new SimpleCalculator();
}

Calculator::~Calculator()
{
    delete ui;
}

/// when first arg is changed i change first arg in calculator and refresh the text in answer
void Calculator::on_firstArgument_valueChanged(int arg1)
{
    calculator->changeFirstArgument(arg1);
    if (calculator->mAnswer() < error)
        ui->answer->setText(QString::number(calculator->mAnswer()));
    else
        ui->answer->setText("error");
}

/// when second arg is changed i change second arg in calculator and refresh the text in answer
void Calculator::on_secondArgument_valueChanged(int arg2)
{
    calculator->changeSecondArgument(arg2);
    if (calculator->mAnswer() < error)
        ui->answer->setText(QString::number(calculator->mAnswer()));
    else
        ui->answer->setText("error");
}

/// when operation is changed i change operation in calculator and refresh the text in answer
void Calculator::on_operation_currentIndexChanged(int index)
{
    calculator->changeOperation(index);
    if (calculator->mAnswer() < error)
        ui->answer->setText(QString::number(calculator->mAnswer()));
    else
        ui->answer->setText("error");
}
