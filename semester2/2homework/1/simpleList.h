#pragma once
#include "list.h"

class SimpleList : public List
{
public:
    SimpleList();
    ~SimpleList();

    void addElement(int value);
    bool deleteElement(int value);
    void print();
    int length();

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

