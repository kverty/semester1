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
    void addValue(const std::string &newString);
    ///returns true if in the table there is wanted string
    bool wasAdded(const std::string &wantedString);
    ///obviously delete some string, if there is no such string returns false
    bool deleteValue(const std::string &wantedString);
    /// it can change hash during the process and rewrite the table
    void newHash(HashFunction *newHash);
    /// show some stats - load factor, number of empty cells
    void stats();

private:
    HashFunction *hash;
    SimpleList* *hashTable;
    int hashTableSize;
    /// clears table
    void clear();
    /// can be resized if load factor is too big
    void resize();
};
