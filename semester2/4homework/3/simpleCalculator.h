#pragma once
#include <QString>
#include "expressions.h"

class SimpleCalculator
{
public:
    SimpleCalculator() : firstArg(0), secondArg(0) {}
    ~SimpleCalculator();
    /// counts the expression
    /// but first sould be used method isCorrect!
    double count();
    /// chaecks if expression is correct and counts firstArg, secondArg and operation
    bool isCorrect(QString expression);
private:
    double firstArg;
    double secondArg;
    QChar operation;
};
