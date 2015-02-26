#include "simpleStack.h"
#include "stack.h"
#include <iostream>

using namespace std;

SimpleStack::SimpleStack() : head(nullptr) {}

SimpleStack::~SimpleStack()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        ListElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

int SimpleStack::length()
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

double SimpleStack::top()
{
    if (head != nullptr)
        return head->value;
    return 0;
}

double SimpleStack::pop()
{
    if (head == nullptr)
        return 0;

    int answer = head->value;
    ListElement *element = head->next;
    delete head;
    head = element;

    return answer;
}

void SimpleStack::push(double value)
{
    head = new ListElement(value, head);
}

void SimpleStack::print()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        cout << element->value << " ";
        element = element->next;
    }
}


SimpleStack::ListElement::ListElement(double value, ListElement *next) : value(value), next(next) {}

