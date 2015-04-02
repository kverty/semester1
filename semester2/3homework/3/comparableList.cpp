#include "comparableList.h"
#include "listComparator.h"
#include <iostream>

using namespace std;

ComparableList::ComparableList() : head(nullptr) {}

ComparableList::~ComparableList()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        ListElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

int ComparableList::length()
{
    return size;
}

void ComparableList::addElement(int value)
{
    head = new ListElement(value, head);
    size++;
}

void ComparableList::print()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        cout << element->value << " ";
        element = element->next;
    }
}

bool ComparableList::deleteElement(int value)
{
    if(head == nullptr)
        return false;

    bool wasFound = false;
    while (head->value == value)
    {
        ListElement *newHead = head->next;
        delete head;
        size--;
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
            size--;
            currentElement->next = element;
            continue;
        }
        currentElement = currentElement->next;
    }
    return wasFound;
}

ComparableList::ListElement::ListElement(int value, ListElement *next) : value(value), next(next) {}
