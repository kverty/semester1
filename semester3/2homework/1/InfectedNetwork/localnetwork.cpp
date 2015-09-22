#include <iostream>
#include "localnetwork.h"

LocalNetwork::LocalNetwork(FILE *inputFile) : computers(new List<Computer*>())
{
    fscanf(inputFile, "%d", &numberOfComputers);

    for (int i = 0; i < numberOfComputers; i++)
    {
        int type = 0;
        Computer *currentComputer;

        fscanf(inputFile, "%d", &type);
        switch (type)
        {
            case 1 : currentComputer = new Computer(0.15);
            case 2 : currentComputer = new Computer(0.12);
        }

        computers->addElement(currentComputer);
    }

    for (int i = 0; i < numberOfComputers; i++)
    {
        Computer *currentComputer = computers->get(i);
        for (int j = 0; j < numberOfComputers; j++)
        {
            int isLinked = 0;

            fscanf(inputFile, "%d", &isLinked);
            if (isLinked)
                currentComputer->addNeighbour(computers->get(j));
        }
    }

    int numberOfInfected = 0;

    fscanf(inputFile, "%d", &numberOfInfected);

    for (int i = 0; i < numberOfInfected; i++)
    {
        int index = 0;

        fscanf(inputFile, "%d", &index);

        computers->get(index)->infectNewlyInfected();
    }

    fclose(inputFile);

}

void LocalNetwork::startThisTurn()
{
    for (int i = 0; i < numberOfComputers; i++)
        computers->get(i)->touchOthers();

    dealWithNewlyInfected();

    writeResults();
}

void LocalNetwork::writeResults()
{
    for (int i = 0; i < numberOfComputers; i++)
        std::cout << (int) computers->get(i)->currentState() << " ";
}

void LocalNetwork::dealWithNewlyInfected()
{
    for (int i = 0; i < numberOfComputers; i++)
        computers->get(i)->infectNewlyInfected();
}
