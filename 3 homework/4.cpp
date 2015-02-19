#include <iostream>

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

    if (i < right)
        qsort(arr, i, right);
    if (left < j)
        qsort(arr, left, j);
}

int main()
{
    cout << "Enter your number : " << endl;

    int n = 0;
    cin >> n;
    cout << n << " -> ";

    int const size = 20;
    int length = 0;
    int digits[size];

    while(n > 0)
    {
        digits[length] = n % 10;
        length++;
        n = n / 10;
    }

    qsort(digits, 0, length - 1);

    int j = 0;
    while (digits[j] == 0)
        j++;

    if (j > 0)
        swap(digits[0], digits[j]);

    for (int i = 0; i < length; i++)
    {
        cout << digits[i];
    }

    return 0;
}
