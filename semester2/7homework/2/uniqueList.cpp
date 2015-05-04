#include "uniqueList.h"
#include <iostream>

using namespace std;

void UniqueList::addElement(int value) throw (DublicateExc)
{
    if (wasAdded(value))
        throw DublicateExc();

    SimpleList::addElement(value);
}

void UniqueList::deleteElement(int value) throw (ElementNotFoundExc)
{
    if (!wasAdded(value))
        throw ElementNotFoundExc();

    SimpleList::deleteElement(value);
}
