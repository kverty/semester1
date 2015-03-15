#pragma once
#include "sort.h"

class InsertSorter : public Sorter
{
public:
    InsertSorter(double *array, int length);
    ~InsertSorter();
    void sort();
};
