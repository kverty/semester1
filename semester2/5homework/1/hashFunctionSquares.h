#pragma once

#include "hashFunction.h"

/// one of 3 hash functions - sum of the squares of the indexes of the letters
class SquareHashFunction : public HashFunction
{
public:
    int count(const std::string &str, int module);
};
