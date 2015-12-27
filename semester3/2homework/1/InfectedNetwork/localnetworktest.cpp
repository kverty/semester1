#include "localnetwork.h"

void NetworkTest::networkTest()
{
    LocalNetwork *testedNetwork = new LocalNetwork(inputFile);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3 - i; j++)
            QVERIFY(testedNetwork->computers->get(j)->currentState() == healthy);

        for (int j = 3 - i; j <= 3 + i; j++)
            QVERIFY(testedNetwork->computers->get(j)->currentState() == infected);

        for (int j = 4 + i; j < 7; j++)
            QVERIFY(testedNetwork->computers->get(j)->currentState() == healthy);

        testedNetwork->startThisTurn();
    }

    delete testedNetwork;
}
