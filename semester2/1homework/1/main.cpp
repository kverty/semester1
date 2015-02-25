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
    return 0;
}

