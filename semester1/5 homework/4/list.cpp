#include "list.h"
#include <iostream>
#include <cstdlib>
#include "string.h"
#include "digits.h"

using namespace std;

struct Contact
{
    long long number;
    char *name;
    int lenght;
};

struct ListElement
{
    Contact *contact;
    ListElement *next;
};

struct List
{
    ListElement *head;
};

Contact *createContact(char *name, int lenght,  long long number)
{
    char *newName = new char[lenght];
    for (int i = 0; i < lenght; i++)
        newName[i] = name[i];

    Contact *newContact = new Contact;
    newContact->name = newName;
    newContact->lenght = lenght;
    newContact->number = number;
    return newContact;
}

ListElement *createListElement(char *name, int lenght,  long long number, ListElement *next)
{
    ListElement *newElement = new ListElement;
    newElement->next = next;
    newElement->contact = createContact(name, lenght, number);
    return newElement;
}

ListElement *createListElement(Contact *contact, ListElement *next)
{
    ListElement *newElement = new ListElement;
    newElement->next = next;
    newElement->contact = contact;
    return newElement;
}

List *createList()
{
    List *newList = new List;
    newList->head = createListElement(nullptr, nullptr);
    return newList;
}


void addValue(List *l, Contact *contact)
{
    ListElement *newElement = createListElement(contact, nullptr);
    newElement->next = l->head->next;
    l->head->next = newElement;
}

void addValue(List *l, char *name, int lenght,  long long number)
{
    ListElement *newElement = createListElement(name, lenght, number, nullptr);
    newElement->next = l->head->next;
    l->head->next = newElement;
}

void readFromFile(List *l)
{
    char nameOfPhonebook[nameSize] = {'\0'};
    scanf("%s", nameOfPhonebook);

    FILE * file = fopen(nameOfPhonebook, "r");
    if (file == NULL)
        cout << "There is no such file!" << endl;
    else
    {

        char name[nameSize] = {'\0'};
        while (fgets(name, nameSize, file) != NULL)
        {
            char number[numberSize];

            fgets(number, numberSize, file);
            addValue(l, createContact(name, strlen(name), stringToInt(number, strlen(number))));
        }
    }
    fclose(file);
}

void writeInFile(List *l)
{
    cout << "Enter the name of the file which do you want to write in : \n";
    char nameOfPhonebook[nameSize];
    scanf("%s", nameOfPhonebook);

    FILE * outputFile = fopen(nameOfPhonebook, "w");
    ListElement *currentElement = l->head->next;

    while (currentElement != nullptr)
    {
        for (int i = 0; i < currentElement->contact->lenght; i++)
            fprintf(outputFile, "%c", currentElement->contact->name[i]);

        if (currentElement->contact->name[currentElement->contact->lenght - 1] != '\n')
            fprintf(outputFile, "\n");

        fprintf(outputFile, "%lld\n", currentElement->contact->number);
        currentElement = currentElement->next;
    }

    fclose(outputFile);
}


bool isEqual(char *name1, int lenght1, char *name2, int lenght2)
{
    bool result = true;
    if (name1[lenght1 - 1] == '\n')
        lenght1--;
    if (name2[lenght2 - 1] == '\n')
        lenght2--;
    if (lenght1 != lenght2)
        result = false;
    for (int i = 0; i < lenght1; i++)
    {
        if (name1[i] != name2[i])
            result = false;
    }
    return result;
}

List *findName(List *l, char *name, int lenght)
{
    List *contactsWithSameName = createList();
    ListElement *currentElement = l->head->next;
    while (currentElement != nullptr)
    {
        if (isEqual(currentElement->contact->name, currentElement->contact->lenght, name, lenght))
            addValue(contactsWithSameName, currentElement->contact);
        currentElement = currentElement->next;
    }
    return contactsWithSameName;
}

ListElement *findNumber(List *l, long long number)
{
    ListElement *currentElement = l->head->next;
    while (currentElement != nullptr)
    {
        if (currentElement->contact->number == number)
            break;
        currentElement = currentElement->next;
    }
    return currentElement;
}

long long stringToInt(char* number, int length)
{
    long long result = 0;
    long long tensPow = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (isDigit(number[i]))
        {
            result += charToInt(number[i]) * tensPow;
            tensPow *= 10;
        }
    }

    return result;
}

void deleteAll(ListElement *element)
{
    if (element != nullptr)
    {
        deleteAll(element->next);
        delete element;
    }
}

void deleteList(List *l)
{
    deleteAll(l->head);
    l->head = nullptr;
}

void clearList(List *l)
{
    deleteAll(l->head->next);
    l->head->next = nullptr;
}

bool isEmpty(List *l)
{
    if (l->head->next == nullptr)
        return true;
    else
        return false;
}

void printElement(ListElement *element)
{
    for (int i = 0; i < element->contact->lenght; i++)
        cout << element->contact->name[i];

    if (element->contact->name[element->contact->lenght - 1] != '\n')
        cout << endl;

    cout << element->contact->number << endl;
}

void printList(List *l)
{
    ListElement *currentElement = l->head->next;
    while (currentElement != nullptr)
    {
        printElement(currentElement);
        currentElement = currentElement->next;
        cout << "--\n";
    }
}



