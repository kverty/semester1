#pragma once
#include "expressions.h"

class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(Token *token) = 0;
    virtual int length() = 0;
    virtual Token *pop() = 0;
    virtual Token *top() = 0;
    virtual void print() = 0;
};
