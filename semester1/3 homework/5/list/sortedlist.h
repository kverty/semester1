#pragma once

struct ListElement
{
    int value;
    ListElement *next;
};

struct SortedList {
    ListElement *head; //head->next.value - самый маленький
};

void createList(SortedList &l);
void printElement(ListElement *element);
void printList(SortedList &l);
void addValue(SortedList &l, int value);
void addValue(int value, ListElement *rightPlace);
void deleteAll(ListElement *element);
void deleteList(SortedList &l);
void clearList(SortedList &l);
bool removeValue(SortedList &l, int value);

