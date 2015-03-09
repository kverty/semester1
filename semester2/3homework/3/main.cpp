#include <iostream>
#include "comparableList.h"
#include "listComparator.h"
#include "sortedSet.h"

using namespace std;

int main()
{
    cout << "Let's make sorted set of comparable lists!" << endl;
    cout << "How many lists do you want?" << endl;

    int numberOfLists = 0;
    cin >> numberOfLists;

    cout << "Now, enter the lists" << endl;

    SortedSet *setOfLists = new SortedSet();

    for (int i = 0; i < numberOfLists; i++)
    {
        cout << "Enter number of elements in " << i + 1 << "rd/nd/th list : " << endl;

        int numberOfElements = 0;
        cin >> numberOfElements;

        cout << "Now, enter the elements : " << endl;

        ComparableList *newList = new ComparableList();

        for (int j = 0; j < numberOfElements; j++)
        {
            int element = 0;
            cin >> element;
            newList->addElement(element);
        }
        setOfLists->addElement(newList);
    }
    setOfLists->print();
    return 0;
}

