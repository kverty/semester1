#include "arrayStack.h"
#include "stack.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack()
{
    size = 4;
    array = new double[size];
    lenght = 0;
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

int ArrayStack::length()
{
    return lenght;
}

double ArrayStack::top()
{
    return array[lenght - 1];
}

double ArrayStack::pop()
{
    if (lenght == 0)
        return 0;
    lenght--;
    return array[lenght];
}

void ArrayStack::push(double value)
{
    if (lenght == size)
    {
        size = size * 2;
        double *newArray = new double[size];
        for (int i = 0; i < lenght; i++)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
    }

    array[lenght] = value;
    lenght++;
}

void ArrayStack::print()
{
    for (int i = lenght - 1; i >= 0; i--)
        cout << array[i] << ' ';
}


