#pragma once
#include "listComparator.h"

///set of ComparableWithSize objects - each two can be compared, so it can be sorted
class SortedSet
{
public:
    SortedSet();
    ~SortedSet();

    void addElement(ComparableWithSize *substance);
    bool deleteElement(ComparableWithSize *substance);
    void print();
    int length();

private:
    /// the same as ListElement, but instead of field int value here is field substance
    /// because it is set of ComparableWithSize objects not int
    class SetElement
    {
    public:
        SetElement(ComparableWithSize *substance, SetElement *next);
        ~SetElement();
        ComparableWithSize *substance;
        SetElement *next;
    };

    SetElement *head;

    void recursiveAdd(ComparableWithSize *substance, SetElement *element);
};
