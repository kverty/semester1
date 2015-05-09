#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n = 0;

    cout << "Enter positive number n :" << endl;
    cin >> n;
    if (n == 1)
    {
        cout << "There are no prime numbers from 1 to n" << endl;
        return 0;
    }

    bool isPrime[n];
    int answer = 0;
    for (int j = 2; j <= n; j++)
        isPrime[j] = true;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            answer++;
            int multiple = i + i;
            while (multiple <= n)
            {
                isPrime[multiple] = false;
                multiple += i;
            }
        }
    }

    cout << "There are " << answer << " prime number";
    if (answer > 1)
        cout << "s";
    cout << " from 1 to " << n << " : " << endl;

    for (int l = 2; l <= n; l++)
    {
        if (isPrime[l])
        {
            cout << l << " ";
        }
    }
    return 0;
}
