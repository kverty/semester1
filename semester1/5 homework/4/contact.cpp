#include <iostream>
#include "contact.h"
#include "digits.h"

using namespace std;

struct Contact
{
    int number;
    Name *name;
};

Contact *createContact(Name *name, int number)
{
    Contact *newContact = new Contact;
    newContact->name = name;
    newContact->number = number;
    return newContact;
}

List *findName(List *l, Name *name)
{
    List *contactsWithSameName = createList();
    ListElement *currentElement = l->head->next->next;
    while (currentElement != nullptr)
    {
        if (isEqual(currentElement->contact->name, name))
            addValue(contactsWithSameName, currentElement);
    }
    return contactsWithSameName;
}

ListElement *findNumber(List *l, int number)
{
    ListElement *currentElement = l->head->next->next;
    while (currentElement != nullptr)
    {
        if (currentElement->contact->number == number)
            break;
    }
    return currentElement;
}

int stringToInt(char number[numberSize], int length)
{
    int result = 0;
    int tensPow = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        if (isDigit(number[i]))
        {
            result += number[i] * tensPow;
            tensPow *= 10;
        }
    }
    return result;
}

void readFromFile(List *l, FILE * file)
{
    char name[nameSize];
    while (fgets(name, nameSize, file) != NULL)
    {
        char number[numberSize];
        fgets(number, numberSize, file);
        addValue(l, createContact(createName(name, strlen(name)), stringToInt(number, strlen(number))));
    }
}

void writeInFile(List *l, FILE * file)
{
    ListElement *currentElement = l->head;
    while (currentElement != nullptr)
    {
        fprintf(file, "%s\n%d\n", element->contact->name->str, element->contact->number);
        currentElement = currentElement->next;
    }
}

