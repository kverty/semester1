#pragma once
#include "list.h"
#include "computer.h"
//#include "linuxcomputer.h"
//#include "windowscomputer.h"

#include <iostream>

class LocalNetwork
{
public:
    LocalNetwork(FILE *inputFile);
    ~LocalNetwork();
    void startThisTurn();

private:
    void writeResults();
    void dealWithNewlyInfected(); // just changes state of some computers

    List<Computer*> *computers;
    int numberOfComputers;
};
