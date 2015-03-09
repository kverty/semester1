#pragma once
#include "output.h"

///interface to print array of number to Console
class ConsoleOutput : public Output
{
public:
    ConsoleOutput(int *array, int length);
    void out();

private:
    int *array;
    int length;
};
