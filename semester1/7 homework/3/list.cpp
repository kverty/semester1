#include "list.h"
#include <iostream>
#include "mystring.h"
#include <cstdlib>

using namespace std;

struct ListElement
{
    MyString *value;
    ListElement *next;
};

struct List
{
    ListElement *head;
};

ListElement *createElement(MyString *value, ListElement *next)
{
    ListElement *element = new ListElement;
    element->next = next;
    element->value = value;
    return element;
}

List *createList()
{
    List *l = new List;
    l->head = createElement(nullptr, nullptr);
    return l;
}

void printElement(ListElement *element)
{
    if (element != nullptr)
    {
        printString(element->value);
        printElement(element->next);
    }
}

void printList(List* &l)
{
    if (l->head->next != nullptr)
    {
        printElement(l->head->next);
        cout << endl;
    }
    else
        cout << "List is empty!" << endl;
}

void addValue(List* &l, MyString *value)
{
    l->head->next = createElement(value, l->head->next);
}

void deleteAll(ListElement *element)
{
    if (element != nullptr)
    {
        deleteAll(element->next);
        deleteMyString(element->value);
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

bool removeValue(List* &l, MyString *value)
{
    ListElement *currentElement = l->head;
    bool valueWasFound = false;
    while (currentElement->next != nullptr)
    {
        if (isEqual(currentElement->next->value, value))
        {
            valueWasFound = true;
            ListElement *element = currentElement->next->next;
            //deleteMyString(currentElement->next->value);
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
