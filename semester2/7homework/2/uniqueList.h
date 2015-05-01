#pragma once
#include "list.h"

class DublicateExc
{

};

class ElementNotFoundExc
{

};

/// list that doesn't contain dublicate values
class UniqueList : public List
{
public:
    UniqueList();
    ~UniqueList();

    /// adds element
    void addElement(int value); //throw (DublicateExc)
    /// removes value
    void deleteElement(int value); //throw (ElementNotFoundExc)
    void print();
    int length();

private:
    /// finds if value was added
    bool wasAdded(int value);

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

