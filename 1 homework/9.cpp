#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int const maxLogN = 64;
    int a = 0;
    int n = 0;

    cout << "Enter a and n(integer), I will count a^n : " << endl;
    cin >> a >> n;

    int m = n;
    int nInBinarySystem[maxLogN];
    int binarySymbols = 0;

    while (m > 0)
    {
        nInBinarySystem[binarySymbols] = m % 2;
        binarySymbols++;
        m = m / 2;
    }

    int aPower = a;
    int answer = 1;

    for (int i = 0; i < binarySymbols; i++)
    {
        if(nInBinarySystem[i] == 1)
        {
            answer *= aPower;
        }
        aPower = aPower * aPower;
    }

    cout << a << "^" << n << " = " << answer << endl;
}
