#pragma once

struct ListElement;
struct List;

List *createList();
void printList(List* &l);
void addValue(List* &l, int weight, int where);
void deleteList(List* &l);
void isolateVertex(List* &l, int where);
int returnMinWeight(List* &l);
int returnNearest(List* &l);
void removeTop(List* &l);
bool isEmpty(List* &l);
