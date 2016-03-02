#include <iostream>
#include "localnetwork.h"

LocalNetwork::LocalNetwork(Generator *generator, FILE *inputFile) : computers(new List<Computer*>())
{
    int numberOfComputers = 0;
    fscanf(inputFile, "%d", &numberOfComputers);

    for (int i = 0; i < numberOfComputers; i++)
    {
        int type = 0;
        Computer *currentComputer;

        fscanf(inputFile, "%d", &type);
        switch (type)
        {
            case 1 : currentComputer = new LinuxComputer(generator); break;
            case 2 : currentComputer = new WindowsComputer(generator); break;
            case 3 : currentComputer = new TestingComputer(generator); break;
        }

        computers->addElement(currentComputer);
    }

    ListIterator<Computer*> *iter1 = new ListIterator<Computer*>(computers);

    for (iter1->first(); !iter1->isDone(); iter1->next())
    {
        ListIterator<Computer*> *iter2 = new ListIterator<Computer*>(computers);

        for (iter2->first(); !iter2->isDone(); iter2->next())
        {
            int isLinked = 0;

            fscanf(inputFile, "%d", &isLinked);

            if (isLinked)
                iter1->currentItem()->addNeighbour(iter2->currentItem());
        }

        delete iter2;
    }

    int numberOfInfected = 0;

    fscanf(inputFile, "%d", &numberOfInfected);

    for (int j = 0; j < numberOfInfected; j++)
    {
        int index = 0;
        fscanf(inputFile, "%d", &index);

        computers->get(index)->infect();
    }

    fclose(inputFile);

    delete iter1;
}

LocalNetwork::~LocalNetwork()
{
    ListIterator<Computer*> *iter = new ListIterator<Computer*>(computers);

    for (iter->first(); !iter->isDone(); iter->next())
        delete iter->currentItem();

    delete iter;
    delete computers;
}

void LocalNetwork::startThisTurn()
{
    ListIterator<Computer*> *iter = new ListIterator<Computer*>(computers);

    for (iter->first(); !iter->isDone(); iter->next())
        iter->currentItem()->touchOthers();

    dealWithNewlyInfected();

    delete iter;
}

void LocalNetwork::writeResults() const
{
    ListIterator<Computer*> *iter = new ListIterator<Computer*>(computers);

    for (iter->first(); !iter->isDone(); iter->next())
        std::cout << iter->currentItem()->currentState() << " ";
    std::cout << "\n";

    delete iter;
}

List<Computer *> *LocalNetwork::getComputers()
{
    return computers;
}

void LocalNetwork::dealWithNewlyInfected()
{
    ListIterator<Computer*> *iter = new ListIterator<Computer*>(computers);

    for (iter->first(); !iter->isDone(); iter->next())
        iter->currentItem()->infectNewlyInfected();

    delete iter;
}
