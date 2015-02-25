#include <iostream>
#include "circledlist.h"

using namespace std;

int main()
{
    cout << "Welcome to Massad roulette" << endl;
    cout << "Enter number of men and period of killing:" << endl;
    cout << "Perion in my definition means - how many people are between two victims" << endl;

    int numberOfMen = 0;
    int period = 0;
    cin >> numberOfMen >> period;

    CircledList l;
    createList(l, numberOfMen);

    for (int i = 0; i < numberOfMen-1; i++)
    {
        //printList(l);
        findNextVictim(l, period);
        kill(l);
    }

    cout << "Survival:" << endl;
    printList(l);

    deleteList(l);

    return 0;
}

