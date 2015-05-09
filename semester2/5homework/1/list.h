#pragma once

class List
{
public:
    virtual ~List() {}
    virtual void addElement(string str) = 0;
    virtual int length() = 0;
    virtual bool deleteElement(string str)= 0;
    virtual void print() = 0;
};

