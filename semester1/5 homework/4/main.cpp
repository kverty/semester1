#include <iostream>
#include <stdio.h>
#include "list.h"
#include "string.h"

using namespace std;

enum Command
{
    theEnd,
    addContact,
    findNumberInList,
    findNameInList,
    writeToFile,
    printAll
};

int main()
{
    List *phonebook = createList();

    cout << "Your phonebook should look like this : " << endl;
    cout << "Ivanov\n5980176\nPetrov\n8 921 744-56-03\n";
    cout << "First line - name, second - number, and it does not matter in wich form your number is" << endl;
    cout << "And there can be two persons with same name, but there is no persons with same number!\n";
    cout << endl;
    cout << "Please, enter name of the phonebook : " << endl;

    readFromFile(phonebook);

    while (true)
    {
        Command command;
        cout << "0. Exit\n1.Add contact\n2.Find number with name\n3.Find name with number\n4.Write to file\n5.Print list\n";
        scanf("%d", &command);

        if (command == theEnd)
            break;

        if (command == addContact)
        {
            char nameOfPerson[nameSize] = {'\0'};
            char number[numberSize] = {'\0'};

            cout << "Enter the name : " << endl;
            scanf("%s", nameOfPerson);
            //gets(nameOfPerson);
            cout << "Enter the number : " << endl;
            scanf("%s", number);

            addValue(phonebook, nameOfPerson, strlen(nameOfPerson), stringToInt(number, strlen(number)));
        }

        if (command == findNumberInList)
        {
            char nameOfPerson[nameSize] = {'\0'};
            cout << "Enter the name : " << endl;
            scanf("%s", nameOfPerson);

            List *foundContacts = findName(phonebook, nameOfPerson, strlen(nameOfPerson));

            if (isEmpty(foundContacts))
                cout << "There is no person with such name!";
            else
                printList(foundContacts);

            deleteList(foundContacts);
            cout << endl;
        }

        if (command == findNameInList)
        {
            char number[numberSize] = {'\0'};
            cout << "Enter the number :\n";
            scanf("%s", number);

            ListElement *foundElement = findNumber(phonebook, stringToInt(number, strlen(number)));

            if (foundElement == nullptr)
                cout << "There is no person with such number!";
            else
                printElement(foundElement);

            cout << endl;
        }

        if (command == printAll)
        {
            printList(phonebook);
            cout << endl;
        }
        if (command == writeToFile)
        {
            writeInFile(phonebook);
        }
    }
    deleteList(phonebook);

    return 0;
}

