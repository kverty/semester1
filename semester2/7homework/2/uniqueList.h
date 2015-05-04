#pragma once
#include "simpleList.h"
#include <exception>

class DublicateExc
{

};

class ElementNotFoundExc
{

};

/// list that doesn't contain dublicate values
class UniqueList : public SimpleList
{
public:
    /// adds element, doesn't add dublicate
    void addElement(int value) throw (DublicateExc);
    /// removes value, throws exception if there is no such element
    void deleteElement(int value) throw (ElementNotFoundExc);
};

