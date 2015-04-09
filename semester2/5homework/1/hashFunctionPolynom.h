#pragma once

#include "hashFunction.h"

/// one of 3 hash functions - hash = value of the polynom
/// letters are coefficients
class PolynomHashFunction : public HashFunction
{
public:
    int count(const std::string &str, int module);
};
