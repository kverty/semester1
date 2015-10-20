#pragma once
#include "linuxcomputer.h"
#include "computer.h"

#include <QObject>
#include <QTest>

class ComputerTest : public QObject
{
   Q_OBJECT
public:
   explicit ComputerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    /// тест, проверяющий правильно ли компьютер заражаетСЯ, с нужной ли вероятностью; тестируется метод attacked()
    void probabilityTest()
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

    /// тест, проверяющий правильно ли компьютер заражает; тестируется метод touchOthers();
    void spreadTest()
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

private:
    int numberOfTests = 20;
    int epsilon = 0.1;
};
