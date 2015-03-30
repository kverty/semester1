#include "sort.h"
#include "qsort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "sortTest.h"

#include <iostream>

using namespace std;

int main()
{
    SorterTest test;
    QTest::qExec(&test);

    /*
    int n = 0;
    cout << "Enter the number of elements : " << endl;
    cin >> n;

    double *array = new double[n];

    cout << "Now, enter the element, please : " << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    Sorter *sorter1 = new QSorter(array, n);
    Sorter *sorter2 = new BubbleSorter(array, n);
    Sorter *sorter3 = new InsertSorter(array, n);

    sorter1->sort();
    sorter2->sort();
    sorter3->sort();

    double *answer1 = sorter1->returnArray();
    double *answer2 = sorter2->returnArray();
    double *answer3 = sorter3->returnArray();

    cout << "QSort : ";
    for (int i = 0; i < n; i++)
    {
        cout << answer1[i] << " ";
    }

    cout << "\n\nBubble : ";
    for (int i = 0; i < n; i++)
    {
        cout << answer2[i] << " ";
    }

    cout << "\n\nInsert : ";
    for (int i = 0; i < n; i++)
    {
        cout << answer3[i] << " ";
    }
    return 0;
    */
}

