#pragma once

class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(int value) = 0;
    virtual int length() = 0;
    virtual int pop() = 0;
    virtual int top() = 0;
    virtual void print() = 0;
};
