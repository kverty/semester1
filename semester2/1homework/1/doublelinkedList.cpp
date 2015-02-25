#include <iostream>
#include "list.h"
#include "doublelinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList() : head(nullptr) {}

DoubleLinkedList::~DoubleLinkedList()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        ListElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

int DoubleLinkedList::length()
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

void DoubleLinkedList::addElement(int value)
{
    head = new ListElement(value, head, nullptr);
    head->next->prev = head;
}

void DoubleLinkedList::print()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        cout << element->value << " ";
        element = element->next;
    }
}

bool DoubleLinkedList::deleteElement(int value)
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
            element->next->prev = element;

        }
        element = element->next;
    }
    return wasFound;
}


DoubleLinkedList::ListElement::ListElement(int value, ListElement *next, ListElement *prev) : value(value), next(next), prev(prev) {}
