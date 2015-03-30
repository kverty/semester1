#pragma once

///sorter - class for sorting array of numbers, and it doesn't matter how we sort it
class Sorter
{
public:
    Sorter(double *array, int length);
    virtual ~Sorter() {}

    ///realization of this method depends on sorting
    virtual void sort() = 0;

    double *returnArray(); 

protected:
    double *array;
    int length;
    bool isSorted;

    ///swap is needed in all kind of sortings, so it is here
    void swap(int x, int y);
};
