#include "computer.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
/*
Computer::Computer(Generator *generator) :
    state(0), neighbours(new List<Computer*>()),
    generator(generator)
{
}
*/
Computer::~Computer()
{
    delete neighbours;
    delete generator;
}

int Computer::currentState() const
{
    return state;
}

void Computer::attacked()
{
    if (state != healthy)
        return;

    if (generator->checkChance(chanceToBeInfected))
        state = newlyInfected;
}

void Computer::touchOthers() const
{
    if (state != infected)
        return;

    ListIterator<Computer*> *iter = new ListIterator<Computer*>(neighbours);

    for (iter->first(); !iter->isDone(); iter->next())
        iter->currentItem()->attacked();

    delete iter;
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
