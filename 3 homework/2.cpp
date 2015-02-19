#include <iostream>
#include "string.h"
#include <stdio.h>

using namespace std;

void swap(char &x, char &y)
{
    char t = x;
    x = y;
    y = t;
}

void qsort(char* arr, int left, int right)
{
    int i = left;
    int j = right;
    int m = (i + j) / 2;

    while (i <= j)
    {
        while (arr[i] - '0' < arr[m] - '0')
            i++;
        while (arr[j] - '0' > arr[m] - '0')
            j--;

        if (i <= j)
        {
            if (arr[i] != arr[j])
                swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (i < right)
        qsort(arr, i, right);
    if (left < j)
        qsort(arr, left, j);
}


int main()
{
    int const size = 100;
    char string1[size];
    char string2[size];

    cout << "Enter two strings, and I will say you if you can rearrange one to another : " << endl;

    cout << "First : " << endl;
    scanf("%s", string1);

    cout << "and second : " <<  endl;
    scanf("%s", string2);

    if (strlen(string1) != strlen(string2))
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        int length = strlen(string1);

        qsort(string1, 0, length - 1);
        qsort(string2, 0, length - 1);

        bool canBeRearranged = true;

        for (int i = 0; i < length; i++)
        {
            if (string1[i] != string2[i])
            {
                canBeRearranged = false;
                break;
            }
        }

        if (canBeRearranged)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
    }
}
