#pragma once
#include "stack.h"

class SimpleStack : public Stack
{
public:
    SimpleStack();
    ~SimpleStack();

    void push(double value);
    int length();
    double pop();
    double top();
    void print();

private:
    class ListElement
    {
    public:
        ListElement(double value, ListElement *next);
        ~ListElement() {}
        double value;
        ListElement *next;
    };

    ListElement *head;
};
