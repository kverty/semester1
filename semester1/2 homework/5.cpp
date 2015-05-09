#include <iostream>

using namespace std;

const int maxSize = 1000;

void swap(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void shiftDown(int* array, int current, int n)
{
    int leftChild = 2 * current;
    int rightChild = leftChild + 1;
    int max = current;
    while (true)
    {
        if ((leftChild < n) && (array[leftChild] > array[max]))
            max = leftChild;

        if ((rightChild < n) && (array[rightChild] > array[max]))
            max = rightChild;

        if (max == current)
            break;
        else
        {
            swap(array[max], array[current]);
            current = max;
            leftChild = 2 * current;
            rightChild = leftChild + 1;
        }
    }
    return;
}

void heapSort(int* array, int length)
{
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        shiftDown(array, i, length);
    }

    for (int j = length - 1; j > 0; j--)
    {
        swap(array[0], array[j]);
        shiftDown(array, 0, j);
    }
}

int main()
{
    int arraySize = 0;
    int array[maxSize];
    cout << "Enter number of elements : " << endl;
    cin >> arraySize;

    cout << "Enter " << arraySize << " elements : " << endl;
    for (int t = 0; t < arraySize; t++)
    {
        cin >> array[t];
    }

    heapSort(array, arraySize);

    cout << "Sorted array : " << endl;
    for (int k = 0; k < arraySize; k++)
    {
        cout << array[k] << " ";
    }
    return 0;
}
