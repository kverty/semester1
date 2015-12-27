#pragma once
#include "list.h"

/// внешний итератор для списка - у меня очень много циклов по элемента этого списка, и с итератором код получается короче
template <class Item>
class ListIterator
{
public:
    ListIterator(List<Item> *list);
    void first();
    void next();
    bool isDone() const;
    Item currentItem() const;
private:
    List<Item>* list;
    int current;
};

template <class Item>
ListIterator<Item>::ListIterator(List<Item> *list)
{
    this->list = list;
    current = 0;
}

template <class Item>
void ListIterator<Item>::first()
{
    current = 0;
}

template <class Item>
void ListIterator<Item>::next()
{
    current++;
}

template <class Item>
bool ListIterator<Item>::isDone() const
{
    return (current >= list->length());
}

template <class Item>
Item ListIterator<Item>::currentItem() const
{
    if (!isDone())
        return list->get(current);
}
