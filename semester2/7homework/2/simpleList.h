#pragma once
#include "list.h"

class SimpleList : public List
{
public:
    SimpleList();
    ~SimpleList();

    void addElement(int value);
    void deleteElement(int value);
    void print();
    int length();
    bool wasAdded(int value);

private:
    class ListElement
    {
    public:
        ListElement(int value, ListElement *next);
        ~ListElement() {}
        int value;
        ListElement *next;
    };

    ListElement *head;
};

