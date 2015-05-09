#include <iostream>
#include "sortedlist.h"

using namespace std;

int main()
{
    cout << "Sorted list realization" << endl << endl;
    SortedList l;
    createList(l);
    while (true)
    {
        cout << "0. Exit" << endl;
        cout << "1. Add value to list" << endl;
        cout << "2. Remove value from list" << endl;
        cout << "3. Print list" << endl;
        cout << "4. Clear list" << endl;

        int command = 0;
        cin >> command;

        if (command == 0)
        {
            cout << "Good bye" << endl;
            deleteList(l);
            break;
        }
        else if (command == 1)roulette
        {
            cout << "Enter new value : " << endl;

            int value = 0;
            cin >> value;
            addValue(l, value);
        }
        else if (command == 2)
        {
            cout << "Which element do you want to remove?" << endl;

            int value = 0;
            cin >> value;
            if (removeValue(l, value))
            {
                cout << "Deleted" << endl;
            }
            else
            {
                cout << "We do not have such value" << endl;
            }
        }
        else if (command == 3)
        {
            printList(l);
        }
        else if (command == 4)
        {
            clearList(l);
            cout << "Cleared" << endl;
        }
        else
        {
            cout << "Wrong command!!" << endl;
        }
    }
    return 0;
}
