#pragma once
#include "stack.h"
#include "expressions.h"


/// stack to count ariphmetic expressions
///
class SimpleStack : public Stack
{
public:
    SimpleStack();
    ~SimpleStack();

    void push(Token *token);
    int length();
    Token *pop();
    Token *top();
    void print();

private:
    class ListElement
    {
    public:
        ListElement(Token *token, ListElement *next);
        ~ListElement() {}
        Token *token;
        ListElement *next;
    };

    ListElement *head;
};
