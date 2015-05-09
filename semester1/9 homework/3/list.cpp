#include "list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct ListElement
{
    int weight;
    int where;
    ListElement *next;
};

struct List {
    ListElement *head;
};

ListElement *createElement(int weight, int where, ListElement *next)
{
    ListElement *element = new ListElement;
    element->next = next;
    element->weight = weight;
    element->where = where;
    return element;
}

List *createList()
{
    List *l = new List;
    l->head = createElement(0, 0, nullptr);
    return l;
}

void printElement(ListElement *element)
{
    if (element != nullptr)
    {
        cout << element->weight << " " << element->where << " // ";
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

void addValue(ListElement* &current, int weight, int where)
{
    if (current->next == nullptr)
        current->next = createElement(weight, where, current->next);
    else
    {
        if (current->next->weight > weight)
        {
            current->next = createElement(weight, where, current->next);
        }
        else
        {
            addValue(current->next, weight, where);
        }
    }
}

void addValue(List* &l, int weight, int where)
{
    if (weight == 0)
        return;
    addValue(l->head, weight, where);
    //cout << weight << " " << where << endl;
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

void removeTop(List* &l)
{
    ListElement *element = l->head->next->next;
    delete l->head->next;
    l->head->next = element;
}

int returnMinWeight(List* &l)
{
    return l->head->next->weight;
}

int returnNearest(List* &l)
{
    return l->head->next->where;
}

bool isEmpty(List* &l)
{
    return (l->head->next == nullptr);
}

void isolateVertex(ListElement* &current, int where)
{
    if (current != nullptr)
    {
        if (current->where == where)
        {
            ListElement *element = current->next;
            delete current;
            current = element;
        }
        else
        {
            isolateVertex(current->next, where);
        }

    }
}

void isolateVertex(List* &l, int where)
{
    isolateVertex(l->head->next, where);
}
