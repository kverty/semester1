#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    calculator = new SimpleCalculator();
    connect(ui->firstArgument, SIGNAL(valueChanged(int)), this, SLOT(onFirstArgumentValueChanged(int)));
    connect(ui->secondArgument, SIGNAL(valueChanged(int)), this, SLOT(onSecondArgumentValueChanged(int)));
    connect(ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(onOperationCurrentIndexChanged(int)));
}

Calculator::~Calculator()
{
    delete ui;
}

/// when first arg is changed i change first arg in calculator and refresh the text in answer
void Calculator::onFirstArgumentValueChanged(int arg1)
{
    calculator->changeFirstArgument(arg1);
    if (calculator->mAnswer() < error)
        ui->answer->setText(QString::number(calculator->mAnswer()));
    else
        ui->answer->setText("error");
}

/// when second arg is changed i change second arg in calculator and refresh the text in answer
void Calculator::onSecondArgumentValueChanged(int arg2)
{
    calculator->changeSecondArgument(arg2);
    if (calculator->mAnswer() < error)
        ui->answer->setText(QString::number(calculator->mAnswer()));
    else
        ui->answer->setText("error");
}

/// when operation is changed i change operation in calculator and refresh the text in answer
void Calculator::onOperationCurrentIndexChanged(int index)
{
    calculator->changeOperation(index);
    if (calculator->mAnswer() < error)
        ui->answer->setText(QString::number(calculator->mAnswer()));
    else
        ui->answer->setText("error");
}
