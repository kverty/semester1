#include <iostream>

using namespace std;

const int maxN = 50;

void swap(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void qsort(int* numer, int* denom, int left, int right)
{
    int i = left;
    int j = right;
    int m = (i + j) / 2;

    while (i <= j)
    {
        while (numer[i] * denom[m] < numer[m] * denom[i])
            i++;
        while (numer[j] * denom[m] > numer[m] * denom[j])
            j--;

        if (i <= j)
        {
            if (numer[i] * denom[j] != numer[j] * denom[i])
            {
                swap(numer[i], numer[j]);
                swap(denom[i], denom[j]);
            }
            i++;
            j--;
        }
    }

    if (i < right)
        qsort(numer, denom, i, right);
    if (left < j)
        qsort(numer, denom, left, j);
}

int main()
{
    int n = 0;
    cout << "Enter maximal denominator : " << endl;
    cin >> n;

    int allNumerators[maxN * maxN];
    int allDenominators[maxN * maxN];
    int size = maxN*maxN;
    for (int i = 0; i < size; i++)
    {
        allNumerators[i] = 0;
        allDenominators[i] = 0;
    }

    allNumerators[0] = 0;
    allDenominators[0] = 1;
    allNumerators[1] = 1;
    allDenominators[1] = 1;

    int numberOfFractions = 2;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
        {
            bool isInArray = false;
            for (int k = 0; k < numberOfFractions; k++)
            {
                if (allNumerators[k] * i == allDenominators[k] * j)
                {
                    isInArray = true;
                    break;
                }
            }
            if (!isInArray)
            {
                allNumerators[numberOfFractions] = j;
                allDenominators[numberOfFractions] = i;
                numberOfFractions++;
            }
        }

    qsort(allNumerators, allDenominators, 0, numberOfFractions - 1);
    qsort(allNumerators, allDenominators, 0, numberOfFractions - 1);

    for (int i = 0; i < numberOfFractions; i++)
    {
        if (allDenominators[i] != 1)
            cout << allNumerators[i] << "/" << allDenominators[i] << " ";
        else
            cout << allNumerators[i] << " ";
    }

    return 0;
}
