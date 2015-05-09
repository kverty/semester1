#pragma once

struct ListElement;
struct List;
enum Token
{
    id,
    addition,
    multiplication,
    openingBracket,
    closingBracket,
    null
};

List *createList();
void printElement(ListElement *element);
void printList(List* &l);
void addValue(List* &l, Token value);
void addValueQueue(List* &l, Token value);
void addValueSorted(List* &l, Token value);
void deleteAll(ListElement *element);
void deleteList(List* &l);
void clearList(List* &l);
bool removeValue(List* &l, Token value);
int length(List* &l);
ListElement *returnElement(List* &l, int index);
