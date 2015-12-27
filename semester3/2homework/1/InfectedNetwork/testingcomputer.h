#pragma once
#include "computer.h"

class TestingComputer : public Computer
{
public:
    TestingComputer()
    {
        chanceToBeInfected = 1;
        state = 0;
        neighbours = new List<Computer *>();
    }
};
