#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
    double x = 0;
    cout << "Enter a number : " << endl;
    cin >> x;

	unsigned char * b = (unsigned char*)&x;
	int bit = 0b10000000;
    int isPositive = true;

	if (b[7] & bit)
        isPositive = false;

    long long power = 1 << 10;
    int exponent = 0;
    bit = bit >> 1;

    for (int i = 1; i < 8; i++)
    {
        if (b[7] & bit)
            exponent += power;
        bit = bit >> 1;
        power = power >> 1;
    }

    bit = 0b10000000;
    for (int i = 0; i < 4; i++)
    {
        if (b[6] & bit)
            exponent += power;
        bit = bit >> 1;
        power = power >> 1;
    }

    double mantissa = 0;
    double mantissaPower = 0.5;

    for (int i = 4; i < 8; i++)
    {

        if (b[6] & bit)
            mantissa += mantissaPower;
        mantissaPower = mantissaPower / 2;
        bit = bit >> 1;
    }

    for (int j = 5; j >= 0; j--)
    {
        bit = 0b10000000;
        for (int i = 0; i < 8; i++)
        {
            if (b[j] & bit)
                mantissa += mantissaPower;
            mantissaPower = mantissaPower / 2;
            bit = bit >> 1;
        }
    }

    exponent = exponent + 1 - (1 << 10);

    if (isPositive)
        cout << "+";
    else
        cout << "-";

    cout << setprecision(52) << mantissa + 1 << "* 2^" << exponent << endl;
    /*
    for (int i = 7; i >= 0; i--)
    {
        int bit = 0b10000000;
        char x = b[i];
        for (int j = 0; j < 8; j++)
        {
            printf((x & bit) ? "1" : "0");
            bit = bit >> 1;
        }
        cout << " ";
    }
    */
    return 0;
}
