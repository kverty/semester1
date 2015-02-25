#include <iostream>
#include "circledlist.h"

using namespace std;

ListElement *createElement(int value)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = nullptr;
    newElement->previous = nullptr;
    return newElement;
}

void addValue(ListElement *element, int value)
{
    element->next = createElement(value);
    element->next->previous = element;
}

void createList(CircledList &l, int numberOfMen)
{
    ListElement *firstElement = createElement(1);
    ListElement *previousElement = firstElement;

    for (int i = 2; i <= numberOfMen; i++)
    {
        addValue(previousElement, i);
        previousElement = previousElement -> next;
    }

    firstElement->previous = previousElement;
    previousElement->next = firstElement;
    l.head = firstElement;
}

void printList(CircledList &l)
{
    ListElement *currentElement = l.head;
    cout << currentElement->value << " ";
    while (currentElement != l.head->previous)
    {
        currentElement = currentElement->next;
        cout << currentElement->value << " ";
    }
    cout << endl;
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

