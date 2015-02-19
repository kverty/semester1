#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int factorialRecursion(int x)
{
    int ans = 1;
    if (x > 1)
    {
        ans = x * factorialRecursion(x - 1);
    }
    return ans;
}

int factorialIteractive(int y)
{
    int answer = 1;
    for (int t = 2; t <= y; t++)
    {
        answer *= t;
    }
    return answer;
}

int main()
{
    int n = 1;

    cout << "Enter positive number n, I will count n! : " << endl;
    cin >> n;

    int answerRecursion = factorialRecursion(n);
    int answerIteractive = factorialIteractive(n);

    cout << "Recursion : " << n << "!  =  " << answerRecursion << endl;
    cout << "Iteractive : " << n << "!  =  " << answerIteractive << endl;
    return 0;
}
