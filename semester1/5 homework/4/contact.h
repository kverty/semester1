#pragma once
#include "name.h"

const int numberSize = 100;

struct Contact;

Contact *createContact(Name *name, int number);

List *findName(List *l, Name *name);
ListElement *findNumber(List *l, int number);
void readFromFile(List *l, FILE * file);
void writeInFile(List *l, FILE * file);

int stringToInt(char number[], int length);



