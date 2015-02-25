#include <iostream>

using namespace std;

const int maxN = 1000;

void writeDifferentSums(int sum, int currentSum, int maxItem, int* allItems)
{
    if (currentSum == sum)
    {
        cout << sum << " = ";
        for (int j = 1; j < maxItem; j++)
        {
            for (int t = 0; t < allItems[j]; t++)
                cout << j << " + ";
        }

        //to get rid of unnecessary plus in the end
        for (int j = 0; j < allItems[maxItem] - 1; j++)
        {
            cout << maxItem << " + ";
        }
        cout << maxItem << endl;

        return;
    }

    int newItem = maxItem + 1;
    int maxNumberOfNewItems = (sum - currentSum) / newItem;

    if (maxNumberOfNewItems == 0)
        return;

    for (int k = 0; k <= maxNumberOfNewItems; k++)
    {
        allItems[newItem] = k;
        writeDifferentSums(sum, currentSum + newItem * k, newItem, allItems);
    }
}

int main()
{
    cout << "Enter N : " << endl;
    int n = 0;
    cin >> n;

    int array[maxN];
    for (int i = 0; i < maxN; i++)
        array[i] = 0;

    int maxTerm = 0;
    writeDifferentSums(n, 0, maxTerm, array);

    return 0;
}
