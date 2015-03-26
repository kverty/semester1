#pragma once
#include "listComparator.h"

///list - it have size, so it is comparableWithSize object
class ComparableList : public ComparableWithSize
{
public:
    /// common methods for list
    ComparableList();
    ~ComparableList();

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

