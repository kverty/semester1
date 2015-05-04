#pragma once

/// set on pointers, elements can be any type
template<typename T>
class Set
{
public:
    Set() : head(nullptr) {}
    ~Set();

    void addValue(const T &value);
    bool deleteValue(const T &value);
    /// checks if this value is in the set
    bool wasAdded(const T &value);
    /// returns size of the set
    int getSize();
    /// unites two sets
    Set<T> unite(Set<T> &set);
    /// intersects two sets
    Set<T> intersect(Set<T> &set);

private:
    class SetElement
    {
    public:
        SetElement(T value, SetElement *next) : value(value), next(next) {}
        ~SetElement() {}
        T value;
        SetElement *next;
    };

    SetElement *head;

};

template<typename T>
Set<T>::~Set()
{
    SetElement *element = head;

    while(element != nullptr)
    {
        SetElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

template<typename T>
int Set<T>::getSize()
{
    SetElement *element = head;
    int length = 0;

    while(element != nullptr)
    {
        length++;
        element = element->next;
    }

    return length;
}

template<typename T>
void Set<T>::addValue(const T &value)
{
    if (!wasAdded(value))
        head = new SetElement(value, head);
}

template<typename T>
bool Set<T>::deleteValue(const T &value)
{
    if (head == nullptr)
        return false;

    bool wasFound = false;
    while (head->value == value)
    {
        SetElement *newHead = head->next;

        delete head;
        head = newHead;
        wasFound = true;

        if(head == nullptr)
            return wasFound;
    }

    SetElement *currentElement = head;
    while (currentElement->next != nullptr)
    {
        if (currentElement->next->value == value)
        {
            SetElement *element = currentElement->next;
            currentElement->next = currentElement->next->next;
            delete element;
            wasFound = true;
        }

        if (currentElement == nullptr)
            break;

        currentElement = currentElement->next;
    }

    return wasFound;
}

template<typename T>
bool Set<T>::wasAdded(const T &value)
{
    if (head == nullptr)
        return false;

    bool wasFound = false;

    SetElement *currentElement = head;
    while (currentElement != nullptr)
    {
        if (currentElement->value == value)
            wasFound = true;

        currentElement = currentElement->next;
    }

    return wasFound;
}

template<typename T>
Set<T> Set<T>::unite(Set<T> &set)
{
    Set<T> resultSet = set;
    SetElement *currentElement = head;
    while (currentElement != nullptr)
    {
        resultSet.addValue(currentElement->value);
        currentElement = currentElement->next;
    }

    return resultSet;
}

template<typename T>
Set<T> Set<T>::intersect(Set<T> &set)
{
    Set<T> resultSet;
    SetElement *currentElement = head;
    while (currentElement != nullptr)
    {
        if (set.wasAdded(currentElement->value))
            resultSet.addValue(currentElement->value);

        currentElement = currentElement->next;
    }

    return resultSet;
}


