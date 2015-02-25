#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void reverse(int* arr, int a, int b)
{
    int medium = (a + b - 1) / 2 + 1;
    for (int i = a; i < medium; i++)
    {
       swap(arr[i], arr[a + b - i]);
    }
}

int main()
{
    int n = 0;
    int m = 0;

    cout << "Enter n and m: " << endl;
    cin >> n >> m;

    cout << "Enter " << n << " elments, first part of array: " << endl;

    int array[n + m];
    for (int j = 0; j < n; j++)
    {
        cin >> array[j];
    }

    cout << "Enter " << m << " elments, first part of array: " << endl;

    int length = n + m;
    for (int k = n; k < length; k++)
    {
        cin >> array[k];
    }
    if (n > 1)
        reverse(array, 0, n - 1);
    if (m > 1)
        reverse(array, n, length - 1);
    reverse(array, 0, length - 1);

    cout << "Result : " << endl;

    for (int t = 0; t < length; t++)
        cout << array[t] << " ";

    return 0;
}
