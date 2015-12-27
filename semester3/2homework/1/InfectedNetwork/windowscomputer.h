#pragma once
#include "computer.h"

class WindowsComputer : public Computer
{
public:
    WindowsComputer()
    {
        chanceToBeInfected = 0.3;
        state = 0;
        neighbours = new List<Computer *>();
    }
};
