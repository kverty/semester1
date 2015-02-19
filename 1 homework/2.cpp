#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;

    cout << "Enter a and b : " << endl;
    cin >> a >> b;

    if (b == 0)
    {
        cout << "You can't divide by zero" << endl;
        return 0;
    }

    int absA = abs(a);
    int absB = abs(b);

    int quotient = 0;

    while (absA >= absB)
    {
        absA -= absB;
        quotient++;
    }

    if ((a > 0) && (b < 0))
        quotient = -quotient;
    if ((a < 0) && (b > 0))
        quotient = -quotient - 1;
    if ((a < 0) && (b < 0))
        quotient = quotient + 1;

    cout << "Partial quotient a / b = " << quotient << endl;
    return 0;
}
