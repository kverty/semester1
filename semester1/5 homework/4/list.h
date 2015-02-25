#pragma once
//#include "name.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int numberSize = 100;
const int nameSize = 100;

struct Contact;

struct ListElement;

struct List;

List *createList();
void printElement(ListElement *element);
void printList(List *l);
void addValue(List *l, char *name, int lenght,  long long number);
void deleteAll(ListElement *element);
void deleteList(List *l);
void clearList(List *l);
bool isEmpty(List *l);

List *findName(List *l, char *name, int lenght);
ListElement *findNumber(List *l, long long number);
void readFromFile(List *l);
void writeInFile(List *l);

long long stringToInt(char *number, int length);


