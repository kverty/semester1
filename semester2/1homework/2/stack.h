#pragma once

class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(double value) = 0;
    virtual int length() = 0;
    virtual double pop() = 0;
    virtual double top() = 0;
    virtual void print() = 0;
};
