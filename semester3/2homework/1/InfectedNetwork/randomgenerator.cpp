#include "randomgenerator.h"
#include <iostream>

RandomGenerator::RandomGenerator()
{
    constForRand = 100;
}

bool RandomGenerator::checkChance(double chance)
{
    int randomNumber = rand() % constForRand;
    return (chance > double(randomNumber) / constForRand);
}
