#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int const size = 100;
    char s[size];

    cout << "Enter your bracket sequence : " << endl;
    scanf("%s", s);

    int length = strlen(s);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(')
            count++;
        if (s[i] == ')')
            count--;
        if (count < 0)
        {
            cout << "Wrong sequence" << endl;
            return 0;
        }
    }
    if (count > 0)
    {
        cout << "Wrong sequence" << endl;
        return 0;
    }
    cout << "Right sequence" << endl;
    return 0;
}
