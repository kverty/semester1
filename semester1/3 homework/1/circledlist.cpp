#include <iostream>
#include "circledlist.h"

using namespace std;

void addValue(ListElement *element, int value)
{
    ListElement *newElement = new ListElement;
    newElement->value = i;
    newElement->next = nullptr;
    newElement->previous = element;
    element->next = newElement;
}

void createList(CircledList &l, int numberOfMen)
{
    ListElement *firstElement = new ListElement;
    firstElement->value = 1;
    firstElement->next = nullptr;
    firstElement->previous = nullptr;
    ListElement *previousElement = firstElement;

    for (int i = 2; i <= n; i++)
    {
        addValue(previousElement, value);
        previousElement = previousElement -> next;
        if (i == n)
        {
            lastElement = previousElement;
        }
    }

    firstElement->previous = lastElement;
    lastElement->next = firstElement;
    l.head = firstElement;
}

void printList(CircledList &l)
{
    ListElement *currentElement = l.head;
    while (currentElement != l.head->previous)
    {
        cout << currentElement->value << " ";
        currentElement = currentElement->next;
    }
}
void findNextVictim(CircledList &l, int period)
{
    for (int i = 0; i < period; i++)
    {
        l.head = l.head->next;
    }
}
void kill(CircledList &l)
{
    l.head->next = l.head->next->next;
    delete l.head->next->previous;
    l.head->next->previous = l.head;
}

void deleteList(CircledList &l)
{
    delete l.head;
}
