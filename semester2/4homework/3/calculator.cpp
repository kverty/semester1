#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    buttons = new QSignalMapper(this);
    /// this array - only to simplify code
    QPushButton *pushButtons[16];

    /// all the buttons are here
    pushButtons[0] = ui->zero;
    pushButtons[1] = ui->one;
    pushButtons[2] = ui->two;
    pushButtons[3] = ui->three;
    pushButtons[4] = ui->four;
    pushButtons[5] = ui->five;
    pushButtons[6] = ui->six;
    pushButtons[7] = ui->seven;
    pushButtons[8] = ui->eight;
    pushButtons[9] = ui->nine;
    pushButtons[10] = ui->dot;
    pushButtons[11] = ui->plus;
    pushButtons[12] = ui->minus;
    pushButtons[13] = ui->mult;
    pushButtons[14] = ui->divide;
    pushButtons[15] = ui->equal;

    /// mapping buttons with values
    for (int i = 0; i <= 9; i++)
    {
        buttons->setMapping(pushButtons[i], '0' + i);
    }
    buttons->setMapping(ui->dot, '.');
    buttons->setMapping(ui->plus, '+');
    buttons->setMapping(ui->minus, '-');
    buttons->setMapping(ui->mult, '*');
    buttons->setMapping(ui->divide, '/');
    buttons->setMapping(ui->equal, '=');

    /// connections
    for (int i = 0; i < 16; i++)
    {
        connect(pushButtons[i], SIGNAL(clicked()), buttons, SLOT(map()));
    }

    connect(buttons, SIGNAL(mapped(int)), this, SLOT(newChar(int)));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::newChar(int symbol)
{
    /// error disappears when user pushes any button
    hasError = false;
    /// if there is nothing there it is simple
    if (expression.length() == 0)
    {
        if (isDigit(symbol))
            expression.push_back(symbol);
    }
    else
    {
        /// some error, such as two dots in the row I avoid here
        /// with lastOne - the last symbol, e.g. if it is operation
        /// and symbol is operation two, then operation changes
        QChar lastOne = expression[expression.length() - 1];
        if (isDigit(symbol))
            expression.push_back(symbol);
        else if (symbol == '=')
        {
            if (!isOperation(lastOne) && lastOne != '.')
            {
                SimpleCalculator *calc = new SimpleCalculator();
                if (calc->isCorrect(expression))
                    expression.setNum(calc->count());
                else
                {
                    ui->lineEdit->setText("Error");
                    expression = "";
                    hasError = true;
                }
            }
        }
        else if (symbol == '.')
        {
            if (lastOne.isDigit())
                expression.push_back('.');
            else
                expression[expression.length() - 1] = '.';
        }
        else
        {
            if (isOperation(lastOne) || lastOne == '.')
                expression[expression.length() - 1] = symbol;
            else
            {
                SimpleCalculator *calc = new SimpleCalculator();
                if (calc->isCorrect(expression))
                {
                    expression.setNum(calc->count());
                    expression += symbol;
                }
                else
                {
                    ui->lineEdit->setText("Error");
                    expression = "";
                    hasError = true;
                }
            }
        }
    }
    if (!hasError)
        ui->lineEdit->setText(expression);
}
