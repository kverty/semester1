#include "sort.h"
#include "bubblesort.h"

BubbleSorter::BubbleSorter(double *array, int length) : Sorter(array, length)
{

}

BubbleSorter::~BubbleSorter()
{
    delete[] array;
}

void BubbleSorter::sort()
{
    if (!isSorted)
    {
        for (int i = length - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
                if (array[j] > array[j + 1])
                    swap(j, j + 1);
        }
    }
}
