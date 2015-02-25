#include <iostream>
#include "circlelist.h"

using namespace std;

int main()
{
    cout << "Massad roulette" << endl;
    cout << "Enter number of men and period of killing:" << endl;

    int numberOfMen = 0;
    int period = 0;
    cin >> numberOfMen >> period;

    CircledList l;
    createList(l, numberOfMen);

    for (int i = 0; i < n-1; i++)
    {
        findNextVictim(l, period);
        kill(l);
    }

    cout << "Survival" << endl;
    print(l);

    deleteList(l);

    return 0;
}
