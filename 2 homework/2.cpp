#include <iostream>

using namespace std;

int main()
{
    int const maxLogN = 64;
    int a = 0;
    int n = 0;

    cout << "Enter a and n(integer), I will count a^n : " << endl;
    cin >> a >> n;

    int m = n;
    int binarySymbols = 0;

    int aPower = a;
    int answer = 1;

    while (m > 0)
    {
        int binaryDigitN = m % 2;
        binarySymbols++;
        m = m / 2;
        if (binaryDigitN == 1)
        {
            answer *= aPower;
        }
        aPower = aPower * aPower;
    }

    cout << a << "^" << n << " = " << answer << endl;
}
