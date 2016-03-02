#pragma once
#include "computer.h"

class WindowsComputer : public Computer
{
public:
    /*
    WindowsComputer(Generator *generator)
    {
        chanceToBeInfected = 0.3;
        Computer(generator);
    }
    */
    WindowsComputer(Generator *generator)
    {
        chanceToBeInfected = 0.3;
        state = 0;
        neighbours = new List<Computer*>();
        this->generator = generator;
    }
};
