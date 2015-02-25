#include <iostream>

using namespace std;

int recursiveFibonacci(int i)
{
    if ((i == 0) || (i == 1))
        return 1;
    return recursiveFibonacci(i - 1) + recursiveFibonacci(i - 2);
}

int iteractiveFibonacci(int i)
{
    int previousFibonacciNumber = 1;
    int fibonacciNumber = 1;

    for (int j = 2; j <= i; j++)
    {
        fibonacciNumber += previousFibonacciNumber;
        previousFibonacciNumber = fibonacciNumber - previousFibonacciNumber;
    }
    return fibonacciNumber;
}

int main()
{
    cout << "Enter index of Fibonacci number you want : " << endl;
    int index = 0;
    cin >> index;

    int recursiveAnswer = recursiveFibonacci(index);
    int iteractiveAnswer = iteractiveFibonacci(index);
    cout << "Iteractive : " << index << "th Fibonacci number is " << iteractiveAnswer  << endl;
    cout << "Recursive : " << index << "th Fibonacci number is " << recursiveAnswer  << endl;
    return 0;
}
