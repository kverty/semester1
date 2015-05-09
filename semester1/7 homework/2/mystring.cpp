#include "mystring.h"
#include <stdio.h>

struct MyString{
    char *str;
    int length;
};


MyString *createMyString(char *str, int length)
{
    MyString *newString = new MyString;
    newString->length = length;
    newString->str = str;
    return newString;
}


void deleteMyString(MyString* &myString)
{
    delete[] myString->str;
    myString->str = nullptr;
    myString->length = 0;
    delete myString;
    myString = nullptr;
}


MyString *clone(MyString *myString)
{
    return createMyString(myString->str, myString->length);
}


MyString *concatenation(MyString *myString1, MyString *myString2)
{
    char *newStr = new char[myString1->length + myString2->length];

    for (int i = 0; i < myString1->length; i++)
        newStr[i] = myString1->str[i];

    for (int i = 0; i < myString2->length; i++)
        newStr[i + myString1->length] = myString2->str[i];

    return createMyString(newStr, myString1->length + myString2->length);
}


bool isEqual(MyString *myString1, MyString *myString2)
{
    if (myString1->length != myString2->length)
        return false;

    bool equal = true;

    for (int i = 0; i < myString1->length; i++)
        equal = equal && (myString1->str[i] == myString2->str[i]);

    return equal;
}


int length(MyString *myString)
{
    return myString->length;
}


bool isEmpty(MyString *myString)
{
    if (myString == nullptr)
        return true;
    else
        return (myString->length == 0);
}


MyString *substring(MyString *myString, int start, int end)
{
    if ((start < 1) || (end > myString->length))
        return nullptr;

    char *newStr = new char[end - start + 1];
    for (int i = 0; i <= end; i++)
        newStr[i] = myString->str[start + i];

    return createMyString(newStr, end - start + 1);
}


char *toChar(MyString *myString)
{
    return myString->str;
}


void printString(MyString *myString)
{
    if (!isEmpty(myString))
        for (int i = 0; i < myString->length; i++)
            printf("%c", myString->str[i]);
}
