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

int SimpleStack::mLength()
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

Token *SimpleStack::top()
{
    if (head != nullptr)
        return head->token;
    return 0;
}

Token *SimpleStack::pop()
{
    if (head == nullptr)
        return 0;

    Token *answer = head->token;
    ListElement *element = head->next;
    delete head;
    head = element;

    return answer;
}

void SimpleStack::push(Token *token)
{
    head = new ListElement(token, head);
}

void SimpleStack::print()
{
    ListElement *element = head;

    while(element != nullptr)
    {
        cout << element->token->number() << " ";
        element = element->next;
    }
}


SimpleStack::ListElement::ListElement(Token *token, ListElement *next) : token(token), next(next) {}

