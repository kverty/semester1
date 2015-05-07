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

bool SimpleList::wasAdded(int value)
{
    ListElement *element = head;
    bool wasFound = false;

    while(element != nullptr)
    {
        if (element->value == value)
            wasFound = true;
        element = element->next;
    }

    return wasFound;
}

void SimpleList::deleteElement(int value)
{
    if(head == nullptr)
        return;

    while(head->value == value)
    {
        ListElement *newHead = head->next;
        delete head;
        head = newHead;
        if(head == nullptr)
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
            continue;
        }
        currentElement = currentElement->next;
    }
}

SimpleList::ListElement::ListElement(int value, ListElement *next) : value(value), next(next) {}
