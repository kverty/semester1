#include <iostream>

using namespace std;

const int size = 100;

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

    if (i < right)
        qsort(arr, i, right);
    if (left < j)
        qsort(arr, left, j);
}

int main()
{
    int n = 0;
    int array[size];

    cout << "Enter length of your array: " << endl;
    cin >> n;

    cout << "Now eneter " << n << " numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    qsort(array, 0, n - 1);

    int j = n - 1;

    while ((j != 0) && (array[j] != array[j - 1]))
        j--;

    if (j == 0)
        cout << "There is no double elements" << endl;
    else
    {
        cout << "Maximal double element in this array is " << array[j] << endl;
    }

    return 0;
}
