#pragma once

class List
{
public:
    virtual ~List() {}
    virtual void addElement(int value) = 0;
    virtual int length() = 0;
    virtual bool deleteElement(int value) = 0;
    virtual void print() = 0;
};

