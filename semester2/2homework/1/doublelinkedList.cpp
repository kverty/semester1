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
    if (head == nullptr)
        head = new ListElement(value, nullptr, nullptr);
    else
    {
        head = new ListElement(value, head, nullptr);
        head->next->prev = head;
    }
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
    if(head == nullptr)
        return false;

    bool wasFound = false;
    if (head->value == value)
    {
        ListElement *newHead = head->next;
        delete head;
        head = newHead;
        head->prev = nullptr;
        wasFound = true;
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
            if (element != nullptr)
                currentElement->next->prev = currentElement;
            continue;
        }
        currentElement = currentElement->next;
    }
    return wasFound;
}


DoubleLinkedList::ListElement::ListElement(int value, ListElement *next, ListElement *prev) : value(value), next(next), prev(prev) {}
