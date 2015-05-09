//#include "list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct ListElement
{
    Token value;
    ListElement *next;
};

struct List {
    ListElement *head;
};

ListElement *createElement(Token value, ListElement *next)
{
    ListElement *element = new ListElement;
    element->next = next;
    element->value = value;
    return element;
}

List *createList()
{
    List *l = new List;
    l->head = createElement(null, nullptr);
    return l;
}

void printToken(Token value)
{
    switch(value)
    {
        case id:
            cout << "id ";
            break;
        case multiplication:
            cout << "*/ ";
            break;
        case addition:
            cout << "+- ";
            break;
        case closingBracket:
            cout << ") ";
            break;
        case openingBracket:
            cout << "( ";
            break;
        default:
            break;
    }
}

void printElement(ListElement *element)
{
    if (element != nullptr)
    {
        printToken(element->value);
        printElement(element->next);
    }
}

void printList(List* &l)
{
    if (l->head->next != nullptr)
    {
        cout << "Tokens : " << endl;
        printElement(l->head->next);
        cout << endl;
    }
    else
    {
        cout << "List is empty!" << endl;
    }
}

void addValue(List* &l, Token value)
{
    l->head->next = createElement(value, l->head->next);
}

void addValueSorted(ListElement* &element, Token value)
{
    if (element->next->value < value)
        element = createElement(value, element);
    else
        addValueSorted(element->next, value);
}

void addValueSorted(List* &l, Token value)
{
    addValueSorted(l->head, value);
}

void addValueQueue(ListElement* &element, Token value)
{
    if (element->next == nullptr)
        element->next = createElement(value, nullptr);
    else
        addValueQueue(element->next, value);
}

void addValueQueue(List* &l, Token value)
{
    addValueQueue(l->head, value);
}

void deleteAll(ListElement *element)
{
    if (element != nullptr)
    {
        deleteAll(element->next);
        delete element;
    }
}

void deleteList(List* &l)
{
    deleteAll(l->head);
    l->head = nullptr;
}

void clearList(List* &l)
{
    deleteAll(l->head->next);
    l->head->next = nullptr;
}

bool removeValue(List* &l, Token value)
{
    ListElement *currentElement = l->head;
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

int length(List *&l)
{
    ListElement *current = l->head;
    int length = 0;
    while (current->next != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}


ListElement *returnElement(List *&l, int index)
{
    ListElement *current = l->head->next;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current;
}
