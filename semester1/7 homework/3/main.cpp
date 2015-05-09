#include <cstdio>
#include <string.h>
#include <iostream>
#include "list.h"
#include "mystring.h"

using namespace std;

const int maxSizeOfName = 100;
const int maxSizeOfLine = 250;

bool isPunctuationSymbol(char c)
{
    return (c == '.' || c == ',' || c == '-' || c == '!' || c == '?' || c == '\'' || c == '"');
}

int main()
{
    FILE* file = NULL;
    char filename[maxSizeOfName];
    int hashTableSize = 100;

    cout << "Please, enter the name of file: " << endl;

    scanf("%s", filename);
    file = fopen(filename,"r");

    if (file == NULL)
    {
        cout << "There is no such file!" << endl;
        fclose(file);
        return 0;
    }
    else
    {
        int numberOfElement = 0;
        List* *hashTable = new List *[hashTableSize];
        for (int i = 0; i < hashTableSize; i++)
            hashTable[i] = createList();

        char line[maxSizeOfLine];
        while (fgets(line, maxSizeOfLine, file) != NULL)
        {
            //printf("%s", line);
            MyString *newString = createMyString(line, strlen(line));
            //printString(newString);
            //cout << length(newString) << endl;
            int start = 0;
            bool wordWasStarted = false;
            for (int i = 0; i < strlen(line); i++)
            {
                //cout << i << " ";
                if (line[i] == ' ' && wordWasStarted)
                {

                    int end = i - 1;
                    while (isPunctuationSymbol(line[end]))
                        end--;
                    if (end > start)
                    {
                        MyString *newWord = substring(newString, start + 1, end + 1);
                        //cout << start + 1 << " " << end + 1;
                        //printString(newWord);
                        addValue(hashTable[countHash(newWord, hashTableSize)], newWord);
                        wordWasStarted = false;
                        numberOfElement++;
                    }
                }
                if (!isPunctuationSymbol(line[i]) && !wordWasStarted)
                {
                    wordWasStarted = true;
                    start = i;
                }
            }
        }
        fclose(file);

        int numberOfEmpty = 0;
        int maxLength = 0;

        for (int i = 0; i < hashTableSize; i++)
        {
            int lengthOfList = length(hashTable[i]);
            if (lengthOfList == 0)
            {
                numberOfEmpty++;
                continue;
            }

            //numberOfElement += lengthOfList;

            if (lengthOfList > length(hashTable[maxLength]))
                maxLength = i;
        }
        cout << "Load factor : " << numberOfElement * 1.0 / (hashTableSize - numberOfEmpty);
        cout << "\nAverage length : " << numberOfElement * 1.0 / hashTableSize;
        cout << "\nMax length : " << length(hashTable[maxLength]) << ": \n";
        printList(hashTable[maxLength]);
        cout << "\nNumber of words : " << numberOfElement;
        cout << "\nNumber of empty : " << numberOfEmpty;

        for (int i = 0; i < hashTableSize; i++)
        {
            deleteList(hashTable[i]);
            delete hashTable[i];
        }
        delete[] hashTable;
    }
    return 0;
}

