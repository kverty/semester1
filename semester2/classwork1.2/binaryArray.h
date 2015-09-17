#pragma once

#include <time.h>

/// return binary array with even number of ones and even number of zeros
int *binaryArray(int size)
{
    int countOfOnes = 0;
    srand(time(NULL));
    int *array = new int[size * size];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = rand() % 2;
        countOfOnes += array[i];
    }

    if (countOfOnes % 2 == 1)
        array[size - 1] = 1;
    else
        array[size - 1] = 0;

    return array;
}
