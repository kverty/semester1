#pragma once
#include <string>

const int startIndex = 'a' - '0' - 1;

/// class for hash function, used in hash table
/// has different succesors - exact hash fucntions
class HashFunction
{
public:
    virtual int count(const std::string &str, int module) = 0;
};
