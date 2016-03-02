#pragma once
#include "computer.h"

class TestingComputer : public Computer
{
public:
    /*
    TestingComputer(Generator *generator)
    {
        chanceToBeInfected = 1;
        Computer(generator);
    }
    */
    TestingComputer(Generator *generator)
    {
        chanceToBeInfected = 1;
        state = 0;
        neighbours = new List<Computer*>();
        this->generator = generator;
    }
};
