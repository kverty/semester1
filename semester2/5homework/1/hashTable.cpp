#include "hashFunction.h"
#include "hashTable.h"
#include "simpleList.h"

#include <iostream>

using namespace std;

void HashTable::clear()
{
    for (int i = 0; i < hashTableSize; i++)
        delete hashTable[i];
    delete[] hashTable;
}

HashTable::HashTable() : hash(nullptr), hashTableSize(5)
{
    hashTable = new SimpleList *[hashTableSize];
    for (int i = 0; i < hashTableSize; i++)
        hashTable[i] = new SimpleList();
}

HashTable::~HashTable()
{
    clear();
    delete hash;
}

void HashTable::addValue(std::string &newString)
{
    if (hash == nullptr)
        return;

    hashTable[hash->count(newString, hashTableSize)]->addElement(newString);
}

bool HashTable::wasAdded(std::string &wantedString)
{
    if (hash == nullptr)
        return false;

    return hashTable[hash->count(wantedString, hashTableSize)]->wasAdded(wantedString);
}

bool HashTable::deleteValue(std::string &wantedString)
{
    if (hash == nullptr)
        return false;

    return hashTable[hash->count(wantedString, hashTableSize)]->deleteElement(wantedString);
}

void HashTable::newHash(HashFunction *newHash)
{
    if (hash == nullptr)
    {
        hash = newHash;
        return;
    }

    delete hash;

    SimpleList* *newHashTable = new SimpleList *[hashTableSize];
    for (int i = 0; i < hashTableSize; i++)
        newHashTable[i] = new SimpleList();

    for (int i = 0; i < hashTableSize; i++)
    {
        while (hashTable[i]->length() > 0)
        {
            std::string str = hashTable[i]->pop();
            newHashTable[newHash->count(str, hashTableSize)]->addElement(str);
        }
    }

    clear();

    hashTable = newHashTable;
    hash = newHash;
}

void HashTable::resize()
{
    SimpleList* *newHashTable = new SimpleList *[2 * hashTableSize];
    for (int i = 0; i < 2 * hashTableSize; i++)
        newHashTable[i] = new SimpleList();

    for (int i = 0; i < hashTableSize; i++)
    {
        while (hashTable[i]->length() > 0)
        {
            std::string str = hashTable[i]->pop();
            newHashTable[hash->count(str, 2 * hashTableSize)]->addElement(str);
        }
    }

    clear();

    hashTable = newHashTable;
    hashTableSize = hashTableSize * 2;
}


void HashTable::stats()
{
    int numberOfEmpty = 0;
    int maxLength = 0;
    int numberOfElement = 0;

    for (int i = 0; i < hashTableSize; i++)
    {
        int lengthOfList = hashTable[i]->length();
        if (lengthOfList == 0)
        {
            numberOfEmpty++;
            continue;
        }

        numberOfElement += lengthOfList;

        if (lengthOfList > hashTable[maxLength]->length())
            maxLength = i;
    }
    cout << "Load factor : " << numberOfElement * 1.0 / (hashTableSize - numberOfEmpty);
    cout << "\nAverage length : " << numberOfElement * 1.0 / hashTableSize;
    cout << "\nMax length : " << hashTable[maxLength]->length() << ": \n";
    hashTable[maxLength]->print();
    cout << "\nNumber of words : " << numberOfElement;
    cout << "\nNumber of empty : " << numberOfEmpty << endl;
}
