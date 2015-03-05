#pragma once

class Sorter
{
public:
    Sorter(double *array, int length);
    virtual ~Sorter() {}
    virtual void sort() = 0;
    //bool isSorted();
    double *returnArray();

protected:
    double *array;
    int length;
    bool isSorted;

    void swap(int x, int y);
};
