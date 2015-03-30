#include <iostream>
#include "doublelinkedList.h"
#include "simpleList.h"

using namespace std;

int main()
{
    List *list = new SimpleList();
    list->addElement(5);
    list->addElement(4);
    list->addElement(5);
    list->addElement(6);
    list->addElement(2);

    list->print();
    cout << endl;

    list->deleteElement(5);

    list->print();
    cout << endl;

    List *list1 = new DoubleLinkedList();
    list1->addElement(5);
    list1->addElement(4);
    list1->addElement(5);
    list1->addElement(6);
    list1->addElement(2);

    list1->print();
    cout << endl;

    delete list;
    return 0;
}

