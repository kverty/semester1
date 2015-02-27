#include "arrayStack.h"
#include "stack.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack()
{
    size = 4;
    array = new int[size];
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

int ArrayStack::top()
{
    return array[lenght - 1];
}

int ArrayStack::pop()
{
    if (lenght == 0)
        return 0;
    lenght--;
    return array[lenght];
}

void ArrayStack::push(int value)
{
    if (lenght == size)
    {
        size = size * 2;
        int *newArray = new int[size];
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


