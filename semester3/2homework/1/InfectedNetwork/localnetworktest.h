#pragma once
#include "computer.h"
#include "linuxcomputer.h"
#include "windowscomputer.h"
#include "testingcomputer.h"
#include "localnetwork.h"
#include "randomgenerator.h"
#include "testgenerator.h"
#include <iostream>
#include <ctime>

#include <QObject>
#include <QTest>

class NetworkTest : public QObject
{
   Q_OBJECT
public:
   explicit NetworkTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void networkTestWithTestingComputers()
    {
        srand(time(0));
        LocalNetwork *testedNetwork = new LocalNetwork(new RandomGenerator(), fopen("testExample.txt", "r"));

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3 - i; j++)
                QVERIFY(testedNetwork->getComputers()->get(j)->currentState() == healthy);

            for (int j = 3 - i; j <= 3 + i; j++)
                QVERIFY(testedNetwork->getComputers()->get(j)->currentState() == infected);

            for (int j = 4 + i; j < 7; j++)
                QVERIFY(testedNetwork->getComputers()->get(j)->currentState() == healthy);

            testedNetwork->startThisTurn();
        }
        delete testedNetwork;
    }

    void integralNetworkTest()
    {
        TestGenerator *generator = new TestGenerator();
        generator->buyValue(0.5);
        generator->buyValue(0.3);

        LocalNetwork *testedNetwork = new LocalNetwork(generator, fopen("testExample2.txt", "r"));

        testedNetwork->startThisTurn();

        QVERIFY(testedNetwork->getComputers()->get(2)->currentState() == infected);
        QVERIFY(testedNetwork->getComputers()->get(1)->currentState() == healthy);
        QVERIFY(testedNetwork->getComputers()->get(0)->currentState() == healthy);

        testedNetwork->startThisTurn();

        QVERIFY(testedNetwork->getComputers()->get(2)->currentState() == infected);
        QVERIFY(testedNetwork->getComputers()->get(1)->currentState() == infected);
        QVERIFY(testedNetwork->getComputers()->get(0)->currentState() == healthy);

        testedNetwork->startThisTurn();
        QVERIFY(testedNetwork->getComputers()->get(2)->currentState() == infected);
        QVERIFY(testedNetwork->getComputers()->get(1)->currentState() == infected);
        QVERIFY(testedNetwork->getComputers()->get(0)->currentState() == healthy);
        delete testedNetwork;
    }
};
