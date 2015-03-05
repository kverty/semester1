#pragma once
#include "output.h"

class ConsoleOutput : public Output
{
public:
    ConsoleOutput(int *array, int length);
    void out();

private:
    int *array;
    int length;
};
