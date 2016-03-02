#pragma once
#include "generator.h"
#include <QVector>

class TestGenerator : public Generator
{
public:
    TestGenerator();
    bool checkChance(double chance);
    void buyValue(double value);
private:
    QVector<double> boughtValues;
    int index;
};
