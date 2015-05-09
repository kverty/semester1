#pragma once
#include "mystring.h"

struct ListElement;
struct List;

List *createList();
void printElement(ListElement *element);
void printList(List* &l);
void addValue(List* &l, MyString *value);
//void addValue(int value, ListElement *rightPlace);
void deleteAll(ListElement *element);
void deleteList(List* &l);
void clearList(List* &l);
bool removeValue(List* &l, MyString *value);
int length(List *&l);
