#pragma once
#include "computer.h"

class LinuxComputer : public Computer
{
public:
    LinuxComputer()// : chanceToBeInfected(0.12), state(healthy), neighbours(new List<Computer *>())
    {
        chanceToBeInfected = 0.12;
        state = 0;
        neighbours = new List<Computer *>();
    }
protected:
    double chanceToBeInfected;
    int state;
    List<Computer *> *neighbours;
};
