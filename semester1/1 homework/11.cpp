#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void swap(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void qsort(int* arr, int left, int right)
{
    int i = left;
    int j = right;
    int m = (i + j) / 2;

    while (i <= j)
    {
        while (arr[i] < arr[m])
            i++;
        while (arr[j] > arr[m])
            j--;

        if (i <= j)
        {
            if (arr[i] != arr[j])
                swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    //cout << l << " " << i << " " << j << " " << " " << r << endl;
    if (i < right)
        qsort(arr, i, right);
    if (left < j)
        qsort(arr, left, j);
}

int main()
{
    int n = 0;

    cout << "Enter number of elements : " << endl;
    cin >> n;

    int array[n]; // array - это вроде какое-то спец-слово

    cout << "Enter " << n << " elements of array : " << endl;

    for (int k = 0; k < n; k++)
    {
        cin >> array[k];
    }

    qsort(array, 0, n - 1);

    cout << "Sorted array : " << endl;
    for (int t = 0; t < n; t++)
    {
        cout << array[t] << " ";
    }

    return 0;
}
