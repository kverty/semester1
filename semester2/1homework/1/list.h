#pragma once

class List
{
public:
    virtual ~List();
    virtual void addElement(int value);
    virtual int length();
    virtual bool deleteElement(int value);
    virtual void print();
};

