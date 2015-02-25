#pragma once
#include "list.h"

class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void addElement(int value);
    bool deleteElement(int value);
    void print();
    int length();

private:
    class ListElement
    {
    public:
        ListElement(int value, ListElement *next, ListElement *prev);
        ~ListElement();
        int value;
        ListElement *next;
        ListElement *prev;
    };

    ListElement *head;
};


