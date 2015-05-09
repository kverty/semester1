#include "list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct ListElement
{
    char *string;
    int length;
    ListElement *next;
};

struct List {
    ListElement *head;
};

ListElement *createElement(char *string, int length, ListElement *next)
{
    char *newString = new char[length];
    for (int i = 0; i < length; i++)
    {
        newString[i] = string[i];
    }
    ListElement *element = new ListElement;
    element->next = next;
    element->string = newString;
    element->length = length;
    return element;
}

List *createList()
{
    List *l = new List;
    l->head = createElement('\0', 0, nullptr);
    return l;
}

void printElement(ListElement *element)
{
    if (element != nullptr)
    {
        printf("%s", element->string);
        printElement(element->next);
    }
}

void printList(List* &l)
{
    if (l->head->next != nullptr)
    {
        cout << "Sorted list : " << endl;
        printElement(l->head->next);
        cout << endl;
    }
    else
    {
        cout << "List is empty!" << endl;
    }
}

void addValue(List* &l, char *string, int length)
{
    //printf("=> was added %d %s", length, string);
    ListElement *element = l->head->next;
    l->head->next = createElement(string, length, nullptr);
    l->head->next->next = element;
}

void deleteAll(ListElement *element)
{
    if (element != nullptr)
    {
        deleteAll(element->next);
        delete element->string;
        delete element;
    }
}

bool isEqual(ListElement *element1, ListElement *element2)
{
    if (element1->length != element2->length)
        return false;

    for (int i = 0; i < element1->length; i++)
        if (element1->string[i] != element2->string[i])
            return false;
    return true;
}

void deleteList(List* &l)
{
    deleteAll(l->head);
    l->head = nullptr;
}

bool wasFound(List* &l, char *string, int length)
{
    //printf("\n%d %s", length, string);
    //cout << "Search: \n";

    ListElement *currentElement = l->head;
    ListElement *element = createElement(string, length, nullptr);
    bool valueWasFound = false;
    while (currentElement->next != nullptr)
    {
        //printf("%d %s", currentElement->next->length, currentElement->next->string);
        if (isEqual(currentElement->next, element))
        {
            valueWasFound = true;
            break;
        }
        currentElement = currentElement->next;
    }
    return valueWasFound;
}


