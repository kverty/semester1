#include "sort.h"

Sorter::Sorter(double *array, int length) : length(length)
{
    double *newArray = new double[length];
    isSorted = true;

    newArray[0] = array[0];
    for (int i = 1; i < length; i++)
    {
        newArray[i] = array[i];
        isSorted = isSorted && (array[i] > array[i - 1]);
    }

    this->array = newArray;
}

double *Sorter::returnArray()
{
    return array;
}

void Sorter::swap(int x, int y)
{
    double temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}
