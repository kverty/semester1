#include "arrayStack.h"
#include "stack.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack() : size(4), length(0), array(new int[4])
{

}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

int ArrayStack::mLength()
{
    return length;
}

int ArrayStack::top()
{
    return array[length - 1];
}

int ArrayStack::pop()
{
    if (length == 0)
        return 0;
    length--;
    return array[length];
}

void ArrayStack::push(int value)
{
    if (length == size)
    {
        size = size * 2;
        int *newArray = new int[size];
        for (int i = 0; i < length; i++)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
    }

    array[lenght] = value;
    length++;
}

void ArrayStack::print()
{
    for (int i = length - 1; i >= 0; i--)
        cout << array[i] << ' ';
}


