#include "sortedlist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void createList(SortedList &l)
{
    ListElement *guard = new ListElement;
    guard->next = nullptr;
    guard->value = 0;
    l.head = guard;
}

void printElement(ListElement *element)
{
    if (element != nullptr)
    {
        cout << element->value << " ";
        printElement(element->next);
    }
}

void printList(SortedList &l)
{
    if (l.head->next != nullptr)
    {
        cout << "Sorted list : " << endl;
        printElement(l.head->next);
        cout << endl;
    }
    else
    {
        cout << "List is empty!" << endl;
    }
}

void addValue(int value, ListElement *rightPlace)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = rightPlace->next;
    rightPlace->next = newElement;
}

void addValue(SortedList &l, int value)
{
    ListElement *currentElement = l.head;
    if (currentElement != nullptr)
    {
        while ((currentElement->next != nullptr) && (currentElement->next->value < value))
        {
            currentElement = currentElement->next;
        }
    }
    addValue(value, currentElement);
}

void deleteAll(ListElement *element)
{
    if (element != nullptr)
    {
        deleteAll(element->next);
        delete element;
    }
}

void deleteList(SortedList &l)
{
    deleteAll(l.head);
    l.head = nullptr;
}

void clearList(SortedList &l)
{
    deleteAll(l.head->next);
    l.head->next = nullptr;
}

bool removeValue(SortedList &l, int value)
{
    ListElement *currentElement = l.head;
    bool valueWasFound = false;
    while (currentElement->next != nullptr)
    {
        if (currentElement->next->value == value)
        {
            valueWasFound = true;
            ListElement *element = currentElement->next->next;
            delete currentElement->next;
            currentElement->next = element;
            continue;
        }
        currentElement = currentElement->next;
    }
    return valueWasFound;
}

