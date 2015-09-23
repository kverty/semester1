#include "computer.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Computer::~Computer()
{
    delete neighbours;
}

int Computer::currentState()
{
    return state;
}

void Computer::attacked()
{
    if (state != healthy)
        return;

    if (chanceToBeInfected > double(rand() % constForRand) / constForRand)
        state = newlyInfected;
}

void Computer::touchOthers()
{
    if (state != infected)
        return;

    int length = neighbours->length();

    for (int i = 0; i < length; i++)
        neighbours->get(i)->attacked();
}

void Computer::infectNewlyInfected()
{
    if (state == newlyInfected)
        state = infected;
}

void Computer::infect()
{
    state = infected;
}

void Computer::addNeighbour(Computer *computer)
{
    neighbours->addElement(computer);
}
