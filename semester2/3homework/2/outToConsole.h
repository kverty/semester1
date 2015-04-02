#pragma once
#include "output.h"

///interface to print array of number to Console
class ConsoleOutput : public Output
{
public:
    ConsoleOutput(int **matrix, int length);
    void out();

private:
    int **matrix;
    int length;
};
