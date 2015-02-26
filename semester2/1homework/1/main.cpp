#include <iostream>
#include "list.h"
#include "doublelinkedList.h"
#include "simpleList.h"

using namespace std;

int main()
{
    List *list = new SimpleList();
    list->addElement(5);
    list->addElement(7);
    list->addElement(10);
    list->addElement(5);
    list->print();
    cout << endl;
    list->deleteElement(5);
    list->print();
    cout << endl;
    list->deleteElement(7);
    list->print();
    cout << endl;
    delete list;

    List *doubleList = new DoubleLinkedList();
    doubleList->addElement(5);
    doubleList->addElement(7);
    doubleList->addElement(10);
    doubleList->addElement(5);
    doubleList->addElement(15);
    doubleList->addElement(25);
    doubleList->print();
    cout << endl;
    doubleList->deleteElement(15);
    doubleList->print();
    cout << endl;
    doubleList->deleteElement(5);
    doubleList->print();
    cout << endl;
    return 0;
}

