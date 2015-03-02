#include "sort.h"
#include "qsort.h"

QSorter::QSorter(double *array, int length) : Sorter(array, length)
{

}

QSorter::~QSorter()
{
    delete[] array;
}

void QSorter::sort()
{
    if (!isSorted)
    {
        qsort(0, length - 1);
        isSorted = true;
    }
}

void QSorter::qsort(int start, int end)
{
    int right = end;
    int left = start;
    double middle = array[(left + right) / 2];
    while (left <= right)
    {
        while (array[left] < middle) left++;
        while (array[right] > middle) right--;
        if (left <= right)
        {
            if (array[left] > array[right])
            {
                swap(left, right);
            }
            left++;
            right--;
        }
    }
    if (left < end)
        qsort(left, end);
    if (start < right)
        qsort(start, right);
}
