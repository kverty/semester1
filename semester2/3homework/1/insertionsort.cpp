#include "sort.h"
#include "insertionsort.h"

InsertSorter::InsertSorter(double *array, int length) : Sorter(array, length)
{

}

InsertSorter::~InsertSorter()
{
    delete[] array;
}

void InsertSorter::sort()
{
    if (!isSorted)
    {
        for (int i = 1; i < length; i++)
        {
            int index = i;
            while (index > 0 && array[index] < array[index - 1])
            {
                swap(index, index - 1);
                index--;
            }
        }
    }
}
