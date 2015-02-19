#include <iostream>

using namespace std;

int main()
{
    int x = 0;

    cout << "Enter x: " << endl;
    cin >> x;

    int y = x * x;
    int answer = (y + 1) * (y + x) + 1;

    cout << "Value of the formula: " << answer << endl;
    return 0;
}
