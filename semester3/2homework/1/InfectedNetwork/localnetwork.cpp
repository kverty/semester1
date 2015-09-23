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
            case 1 : currentComputer = new LinuxComputer(); break;
            case 2 : currentComputer = new WindowsComputer(); break;
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

        computers->get(index)->infect();
    }

    fclose(inputFile);

}

LocalNetwork::~LocalNetwork()
{
    delete computers;
}

void LocalNetwork::startThisTurn()
{
    for (int i = 0; i < numberOfComputers; i++)
        computers->get(i)->touchOthers();

    dealWithNewlyInfected();
}

void LocalNetwork::writeResults()
{
    for (int i = 0; i < numberOfComputers; i++)
        std::cout << computers->get(i)->currentState() << " ";
    std::cout << "\n";
}

void LocalNetwork::dealWithNewlyInfected()
{
    for (int i = 0; i < numberOfComputers; i++)
        computers->get(i)->infectNewlyInfected();
}
