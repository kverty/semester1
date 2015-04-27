#include "simpleCalculator.h"
#include <QChar>

double SimpleCalculator::count()
{
    if (operation == '+')
        return firstArg + secondArg;
    if (operation == '-')
        return firstArg - secondArg;
    if (operation == '*')
        return firstArg * secondArg;
    if (operation == '/')
        return firstArg / secondArg;
    return firstArg;
}

bool SimpleCalculator::isCorrect(QString expression)
{
    int i = 0;
    int digitsAfterDot = 0;

    if (expression[i] == '-')
        i++;

    while(!isOperation(expression[i]) && i < expression.length())
    {
        if (expression[i] == '.' && digitsAfterDot == 0)
        {
            digitsAfterDot++;
        }
        else if (expression[i] == '.' && digitsAfterDot > 0)
        {
            return false;
        }
        else
        {
            firstArg = firstArg * 10 + expression[i].digitValue();
            if (digitsAfterDot > 0)
                digitsAfterDot++;
        }

        i++;
    }

    int tensPow = 1;
    for (int j = 1; j < digitsAfterDot; j++)
        tensPow *= 10;

    firstArg = firstArg / tensPow;

    if (expression[0] == '-')
        firstArg *= -1;

    operation = expression[i];
    i++;
    digitsAfterDot = 0;

    while(i < expression.length())
    {
        if (expression[i] == '.' && digitsAfterDot == 0)
        {
            digitsAfterDot++;
        }
        else if (expression[i] == '.' && digitsAfterDot > 0)
        {
            return false;
        }
        else
        {
            secondArg = secondArg * 10 + expression[i].digitValue();
            if (digitsAfterDot > 0)
                digitsAfterDot++;
        }

        i++;
    }

    tensPow = 1;
    for (int j = 1; j < digitsAfterDot; j++)
        tensPow *= 10;

    secondArg = secondArg / tensPow;

    if (operation == '/' && secondArg == 0)
        return false;

    return true;
}


