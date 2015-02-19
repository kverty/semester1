#pragma once

struct ListElement;
struct List;

List *createList();
void printList(List* &l);
void addValue(List* &l, char *string, int length);
void deleteList(List* &l);
bool wasFound(List* &l, char *string, int length);
