#pragma once
#include "sort.h"

class QSorter : public Sorter
{
public:
    QSorter(double *array, int length);
    ~QSorter();
    void sort();

private:
    void qsort(int left, int right);
};
