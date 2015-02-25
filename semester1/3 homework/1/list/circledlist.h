#pragma once

struct ListElement
{
    int value;
    ListElement *next;
    ListElement *previous;
};

struct CircledList {
    ListElement *head;
};

void addValue(ListElement *element, int value);
void createList(CircledList &l, int numberOfMen);
void printList(CircledList &l);
void findNextVictim(CircledList &l, int period);
void kill(CircledList &l);
void deleteList(CircledList &l);
