#pragma once
#include "computer.h"

class WindowsComputer : public Computer
{
public:
    WindowsComputer()// : chanceToBeInfected(0.15), state(healthy), neighbours(new List<Computer *>())
    {
        chanceToBeInfected = 0.5;
        state = 0;
        neighbours = new List<Computer *>();
    }
//protected:
//    double chanceToBeInfected;
//    int state;
//    List<Computer *> *neighbours;
};
