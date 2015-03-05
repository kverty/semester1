#pragma once
#include "sort.h"

class BubbleSorter : public Sorter
{
public:
    BubbleSorter(double *array, int length);
    ~BubbleSorter();
    void sort();
};
