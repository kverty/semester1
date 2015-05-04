#pragma once
#include "simpleList.h"
#include <exception>

class DublicateException
{

};

class ElementNotFoundException
{

};

/// list that doesn't contain dublicate values
class UniqueList : public SimpleList
{
public:
    /// adds element, doesn't add dublicate
    void addElement(int value) throw (DublicateException);
    /// removes value, throws exception if there is no such element
    void deleteElement(int value) throw (ElementNotFoundException);
};

