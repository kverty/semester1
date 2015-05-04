#include "simpleList.h"
#include "list.h"
#include <iostream>

using namespace std;

SimpleList::SimpleList() : head(nullptr) {}

SimpleList::~SimpleList()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        ListElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

int SimpleList::length()
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

void SimpleList::addElement(int value)
{
    head = new ListElement(value, head);
}

void SimpleList::print()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        cout << element->value << " ";
        element = element->next;
    }
}

bool SimpleList::deleteElement(int value)
{
    if(head == nullptr)
        return false;

    bool wasFound = false;
    while(head->value == value)
    {
        ListElement *newHead = head->next;
        delete head;
        head = newHead;
        wasFound = true;
        if(head == nullptr)
            return wasFound;
    }

    ListElement *currentElement = head;
    while (currentElement->next != nullptr)
    {
        if (currentElement->next->value == value)
        {
            wasFound = true;
            ListElement *element = currentElement->next->next;
            delete currentElement->next;
            currentElement->next = element;
            continue;
        }
        currentElement = currentElement->next;
    }

    return wasFound;
}

SimpleList::ListElement::ListElement(int value, ListElement *next) : value(value), next(next) {}
