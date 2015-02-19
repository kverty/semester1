#pragma once

struct MyString;

MyString *createMyString(char *str, int length);
void deleteMyString(MyString *&myString);
MyString *clone(MyString *myString);
MyString *concatenation(MyString *myString1, MyString *myString2);
bool isEqual(MyString *myString1, MyString *myString2);
int length(MyString *myString);
bool isEmpty(MyString *myString);
MyString *substring(MyString *myString, int start, int end);
char *toChar(MyString *myString);
void printString(MyString *myString);
