#pragma once

#include "simpleList.h"
#include "hashFunction.h"
#include <string>

/// hash table for string
class HashTable
{
public:
    HashTable();
    ~HashTable();
    ///adds value, that shuld be string
    void addValue(std::string newString);
    ///returns true if in the table there is wanted string
    bool wasAdded(std::string wantedString);
    ///obviously delete some string, if there is no such string returns false
    bool deleteValue(std::string wantedString);
    /// it can change hash during the process and rewrite the table
    void newHash(HashFunction *newHash);
    /// show some stats - load factor, number of empty cells
    void stats();

private:
    HashFunction *hash;
    SimpleList* *hashTable;
    int hashTableSize;
    /// can be resized if load factor is too big
    void resize();
};
