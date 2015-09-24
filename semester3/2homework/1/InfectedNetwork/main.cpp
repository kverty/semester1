#include <iostream>
#include <ctime>

#include "localnetwork.h"
#include "computertest.h"

const int maxSizeOfName = 100;

using namespace std;

enum Command
{
    nextTurn = 1,
    results,
    theEnd
};

int main()
{
    ComputerTest test;
    QTest::qExec(&test);

    srand(time(0));

    FILE * file = NULL;
    char filename[maxSizeOfName];

    cout << "Please, enter the name of the file with the number of vertexes and matrix : " << endl;

    scanf("%s", filename);
    file = fopen (filename, "r");

    if (file == NULL)
    {
        cout << "There is no such file!" << endl;
        fclose (file);
        return 0;
    }

    LocalNetwork *network = new LocalNetwork(file);
    bool inProcess = true;

    while (inProcess)
    {
        int command = 0;
        cout << "1. Next turn\n"
                "2. Write results of infection\n"
                "3. Exit\n";
        cin >> command;
        switch (command)
        {
            case nextTurn: network->startThisTurn(); break;
            case results: network->writeResults(); break;
            case theEnd: inProcess = false; break;
        }
    }

    delete network;
    return 0;
}
