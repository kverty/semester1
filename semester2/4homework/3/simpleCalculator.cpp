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
    int tensPow = 1;

    if (expression[i] == '-')
        i++;

    while(!isOperation(expression[i]) && i < expression.length())
    {
        if (expression[i] == '.' && tensPow == 1)
        {
            tensPow *= 10;
        }
        else if (expression[i] == '.' && tensPow > 1)
        {
            return false;
        }
        else
        {
            firstArg = firstArg * 10 + expression[i].digitValue();
            if (tensPow > 1)
                tensPow *= 10;
        }

        i++;
    }

    firstArg = firstArg / tensPow;

    if (expression[0] == '-')
        firstArg *= -1;

    operation = expression[i];
    i++;
    tensPow = 1;

    while(i < expression.length())
    {
        if (expression[i] == '.' && tensPow == 1)
        {
            tensPow *= 10;
        }
        else if (expression[i] == '.' && tensPow > 1)
        {
            return false;
        }
        else
        {
            secondArg = secondArg * 10 + expression[i].digitValue();
            if (tensPow > 1)
                tensPow *= 10;
        }

        i++;
    }

    secondArg = secondArg / tensPow;

    if (operation == '/' && secondArg == 0)
        return false;

    return true;
}


