#pragma once
#include "list.h"
//#include "localnetwork.h"

const int constForRand = 100;

enum State
{
    healthy,
    newlyInfected,
    infected
};

class Computer
{
public:
    ~Computer();
    int currentState();
    void attacked();
    void touchOthers();
    void infectNewlyInfected();
    void infect();
    void addNeighbour(Computer *computer);

protected:
    double chanceToBeInfected;
    int state;
    List<Computer *> *neighbours;
};
