#include "arrayStack.h"
#include "stack.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack() : size(4), length(0), array(new Token*[4])
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

Token *ArrayStack::top()
{
    if (length == 0)
        return nullptr;
    return array[length - 1];
}

Token *ArrayStack::pop()
{
    if (length == 0)
        return nullptr;
    length--;
    return array[length];
}

void ArrayStack::push(Token *token)
{
    if (length == size)
    {
        size = size * 2;
        Token* *newArray = new Token*[size];
        for (int i = 0; i < length; i++)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
    }

    array[length] = token;
    length++;
}

void ArrayStack::print()
{
    for (int i = length - 1; i >= 0; i--)
        cout << array[i]->mNumber() << ' ';
}


