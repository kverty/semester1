#include "computer.h"
#include "linuxcomputer.h"
#include "list.h"

void ComputerTest::probabilityTest()
{
    Computer *testedComputer;
    int numberOfInfected = 0;

    for (int i = 0; i < numberOfTests; i++)
    {
        testedComputer = new LinuxComputer();

        testedComputer->attacked();
        if (testedComputer->currentState() != healthy)
            numberOfInfected++;

        delete testedComputer;
    }

    QVERIFY(abs(double(numberOfInfected)/numberOfTests - 0.5) < 0.1);
}

void ComputerTest::spreadTest()
{
    Computer **testComputers = new Computer *[numberOfTests];
    int numberOfInfected = 0;

    Computer *infectedComputer = new LinuxComputer();
    infectedComputer->infect();

    for (int i = 0; i < numberOfTests; i++)
    {
        testComputers[i] = new LinuxComputer();
        infectedComputer->addNeighbour(testComputers[i]);
    }

    infectedComputer->touchOthers();

    for (int i = 0; i < numberOfTests; i++)
    {
        if (testComputers[i]->currentState() != healthy)
            numberOfInfected++;

        delete testComputers[i];
    }
    delete testComputers;

    QVERIFY(abs(double(numberOfInfected)/numberOfTests - 0.5) < 0.1);
}
