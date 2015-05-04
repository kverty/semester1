#include "uniqueList.h"
#include <iostream>

using namespace std;

void UniqueList::addElement(int value) throw (DublicateException)
{
    if (wasAdded(value))
        throw DublicateException();

    SimpleList::addElement(value);
}

void UniqueList::deleteElement(int value) throw (ElementNotFoundException)
{
    if (!wasAdded(value))
        throw ElementNotFoundException();

    SimpleList::deleteElement(value);
}
