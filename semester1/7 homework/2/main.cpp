#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    MyString *string1 = createMyString("abc", 3);
    MyString *string2 = createMyString("defghijk", 8);



    printString(string1);
    printf("\n");
    printString(string2);
    printf("\n");



    MyString *string3 = clone(string1);
    printString(string1);
    cout << " = ";
    printString(string3);
    cout << "? ";

    if (isEqual(string1, string3))
        cout << "Yes\n";
    else
        cout << "No\n";



    printString(string3);
    cout << " + ";
    printString(string2);
    cout << " = ";

    string1 = concatenation(string3, string2);
    printString(string1);
    printf("\n");



    printString(string1);
    cout << " = ";
    printString(string3);
    cout << "? ";

    if (isEqual(string1, string3))
        cout << "Yes\n";
    else
        cout << "No\n";



    printString(string2);
    cout << " from 2 to 4 = ";

    MyString *string5 = substring(string2, 2, 4);
    printString(string5);
    printf(" length = %d\n", length(string5));

    deleteMyString(string1);
    deleteMyString(string2);
    deleteMyString(string3);
    deleteMyString(string5);


    return 0;
}

