#pragma once

class Calculator
{
public:
    Calculator(char *expression, int length);
    ~Calculator();
    int countUp();

private:
    char *expression;
    int length;
};
