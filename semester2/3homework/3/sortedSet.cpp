#include "sortedSet.h"
#include "listComparator.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet() : head(nullptr)
{

}

SortedSet::~SortedSet()
{
    SetElement *element = head;

    while(element != nullptr)
    {
        SetElement *nextElement = element->next;
        delete element->substance;
        delete element;
        element = nextElement;
    }
}

void SortedSet::recursiveAdd(ComparableWithSize *substance, SetElement *element)
{
    if (element->next == nullptr || substance->CompareTo(element->next->substance) == smaller)
    {
        element->next = new SetElement(substance, element->next);
        return;
    }
    recursiveAdd(substance, element->next);
}

void SortedSet::addElement(ComparableWithSize *substance)
{
    if (head == nullptr)
    {
        head = new SetElement(substance, nullptr);
        return;
    }
    if (substance->CompareTo(head->substance) == smaller)
    {
        head = new SetElement(substance, head);
        return;
    }
    recursiveAdd(substance, head);
}

bool SortedSet::deleteElement(ComparableWithSize *substance)
{
    if(head == nullptr)
        return false;

    bool wasFound = false;
    if (head->substance->CompareTo(substance) == equall)
    {
        SetElement *newHead = head->next;
        delete head;
        head = newHead;
        wasFound = true;
    }

    SetElement *currentElement = head;
    while (currentElement->next != nullptr)
    {
        if (currentElement->next->substance->CompareTo(substance) == equall)
        {
            wasFound = true;
            SetElement *element = currentElement->next->next;
            delete currentElement->next;
            currentElement->next = element;
            continue;
        }
        currentElement = currentElement->next;
    }
    return wasFound;
}

int SortedSet::length()
{
    SetElement *element = head;
    int answer = 0;

    while(element != nullptr)
    {
        answer++;
        element = element->next;
    }

    return answer;
}

void SortedSet::print()
{
    SetElement *element = head;
    int index = 0;

    while(element != nullptr)
    {
        index++;
        cout << endl << index << ". ";
        element->substance->print();
        element = element->next;
    }
    cout << endl;
}

SortedSet::SetElement::SetElement(ComparableWithSize *substance, SetElement *next) : next(next), substance(substance)
{

}

SortedSet::SetElement::~SetElement()
{
    delete substance;
}
