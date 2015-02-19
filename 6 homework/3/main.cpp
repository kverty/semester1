#include <iostream>
#include "tree.h"

using namespace std;

enum Command
{
    theEnd,
    addNumber,
    removeNumber,
    findNumber,
    ascending,
    descending,
    goodPrint
};

int main()
{
    AVLTree *tree = createTree();
    while(true)
    {
        cout << "0.Exit\n1.Add number\n2.Remove number\n3.Find number\n4.Print all numbers, ascending\n5.Print all numbers, descending\n6.Print tree with brackets\n";
        int commandCode = 0;
        cin >> commandCode;
        Command command = static_cast<Command>(commandCode);

        if (command == theEnd)
        {
            deleteTree(tree);
            return 0;
        }
        if (command == addNumber)
        {
            int value;
            cout << "Please, enter the number which you want to add: \n";
            cin >> value;

            addElement(tree, value);
        }
        if (command == removeNumber)
        {
            int value;
            cout << "Please, enter the number which you want to delete: \n";
            cin >> value;

            deleteElementInTree(tree, value);
        }
        if (command == findNumber)
        {
            int value;
            cout << "Please, enter the number which you want to find: \n";
            cin >> value;

            if (wasFound(tree, value))
                cout << "There is such number\n";
            else
                cout << "There is no such number\n";
        }
        if (command == ascending)
        {
            ascendingPrint(tree);
        }
        if (command == descending)
        {
            descendingPrint(tree);
        }
        if (command == goodPrint)
        {
            printTree(tree);
        }

        cout << endl;
    }
}

