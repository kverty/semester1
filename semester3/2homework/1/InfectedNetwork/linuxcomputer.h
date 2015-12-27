#pragma once
#include "computer.h"

class LinuxComputer : public Computer
{
public:
    LinuxComputer()
    {
        chanceToBeInfected = 0.5;
        state = 0;
        neighbours = new List<Computer *>();
    }
};
