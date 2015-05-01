#include "uniqueList.h"
#include "list.h"
#include <iostream>

using namespace std;

UniqueList::UniqueList() : head(nullptr) {}

UniqueList::~UniqueList()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        ListElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

int UniqueList::length()
{
    int length = 0;
    ListElement *element = head;

    while(element != nullptr)
    {
        element = element->next;
        length++;
    }
    return length;
}

bool UniqueList::wasAdded(int value)
{
    ListElement *element = head;

    bool wasFound = false;
    while(element != nullptr)
    {
        if (element->value == value)
        {
            wasFound = true;
            break;
        }
        element = element->next;
    }
    return wasFound;
}

void UniqueList::addElement(int value) //throw (DublicateExc)
{
    if (wasAdded(value))
        throw DublicateExc();

    head = new ListElement(value, head);
}

void UniqueList::print()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        cout << element->value << " ";
        element = element->next;
    }
}

void UniqueList::deleteElement(int value) //throw (ElementNotFoundExc)
{
    if (!wasAdded(value))
        throw ElementNotFoundExc();

    if(head->value == value)
    {
        ListElement *newHead = head->next;
        delete head;
        head = newHead;
        return;
    }
    ListElement *currentElement = head;
    while (currentElement->next != nullptr)
    {
        if (currentElement->next->value == value)
        {
            ListElement *element = currentElement->next->next;
            delete currentElement->next;
            currentElement->next = element;
            return;
        }
        currentElement = currentElement->next;
    }
}

UniqueList::ListElement::ListElement(int value, ListElement *next) : value(value), next(next) {}
