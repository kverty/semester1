#include "testgenerator.h"


TestGenerator::TestGenerator()
{
    index = 0;
}

bool TestGenerator::checkChance(double chance)
{
    index = (index + 1) % boughtValues.length();
    return (boughtValues.at(index) > chance);
}

void TestGenerator::buyValue(double value)
{
    boughtValues.append(value);
}
