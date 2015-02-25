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
    ListElement *element = head;

    if(element == nullptr)
        return false;

    bool wasFound = false;

    while(element != nullptr)
    {
        if (element->next->value == value)
        {
            wasFound = true;
            ListElement *newNext = element->next->next;
            delete element->next;
            element->next = newNext;

        }
        element = element->next;
    }
    return wasFound;
}

SimpleList::ListElement::ListElement(int value, ListElement *next) : value(value), next(next) {}
