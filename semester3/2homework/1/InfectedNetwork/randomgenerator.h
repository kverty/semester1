#pragma once
#include "generator.h"
#include <time.h>
#include <QtGlobal>

class RandomGenerator : public Generator
{
public:
    RandomGenerator();
    bool checkChance(double chance);
private:
    int constForRand;
};
