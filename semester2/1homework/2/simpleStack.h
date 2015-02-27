#pragma once
#include "stack.h"

class SimpleStack : public Stack
{
public:
    SimpleStack();
    ~SimpleStack();

    void push(int value);
    int length();
    int pop();
    int top();
    void print();

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
