#include "computer.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Computer::~Computer()
{
    delete neighbours;
}

int Computer::currentState() const
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

void Computer::touchOthers() const
{
    if (state != infected)
        return;

    ListIterator<Computer*> *iter = new ListIterator<Computer*>(neighbours);

    for (iter->first(); !iter->isDone(); iter->next())
        iter->currentItem()->attacked();
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

void Computer::addNeighbour(Computer *computer) const
{
    neighbours->addElement(computer);
}
