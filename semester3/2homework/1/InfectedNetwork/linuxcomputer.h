#pragma once
#include "computer.h"

class LinuxComputer : public Computer
{
public:
    /*
    LinuxComputer(Generator *generator)
    {
        chanceToBeInfected = 0.5;
        Computer(generator);
    }
    */
    LinuxComputer(Generator *generator)
    {
        chanceToBeInfected = 0.5;
        state = 0;
        neighbours = new List<Computer*>();
        this->generator = generator;
    }
};
