#pragma once
#include <iostream>

using namespace std;

template <class Item>

class List
{
public:
    List() : head(nullptr) {}
    ~List();

    void addElement(Item value);
    bool deleteElement(Item value);
    Item get(int index);
    int length();

private:
    class ListElement
    {
    public:
        ListElement(Item value, ListElement *next);
        ~ListElement() {}
        Item value;
        ListElement *next;
    };

    ListElement *head;
};

template <class Item>
List<Item>::~List()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        ListElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

template <class Item>
int List<Item>::length()
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

template <class Item>
void List<Item>::addElement(Item value)
{
    head = new ListElement(value, head);
}

template <class Item>
bool List<Item>::deleteElement(Item value)
{
    if(head == nullptr)
        return false;

    bool wasFound = false;
    while(head->value == value)
    {
        ListElement *newHead = head->next;
        delete head;
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
            currentElement->next = element;
            continue;
        }
        currentElement = currentElement->next;
    }

    return wasFound;
}

template <class Item>
Item List<Item>::get(int index)
{
    ListElement *element = head;

    for (int i = 0; i < index; i++)
        element = element->next;

    return element->value;
}

template <class Item>
List<Item>::ListElement::ListElement(Item value, ListElement *next) : value(value), next(next) {}
