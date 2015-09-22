#include "computer.h"
#include <cstdlib>

int Computer::currentState()
{
    return state;
}

void Computer::attacked()
{
    if (state != healthy)
        return;

    //srand(time(0));

    if (chanceToBeInfected > 0)//rand(constForRand) / constForoRand)
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
    state = infected;
}

void Computer::addNeighbour(Computer *computer)
{
    neighbours->addElement(computer);
}
