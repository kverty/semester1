#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int const size = 100;
    char s[size];

    cout << "Enter the string that you want to check if it is palindrome : " << endl;
    scanf("%s", s);

    int length = strlen(s);
    bool isPalindrome = true;

    for (int i = 0; i < length; i++)
    {
        if (s[i] != s[length - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
    {
        cout << "It is Palindrome" << endl;
    }
    else
    {
        cout << "It is not Palindrome" << endl;
    }
    return 0;
}
