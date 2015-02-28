#include <iostream>
#include "stack.h"
#include "simpleStack.h"
#include "calculator.h"
#include <string.h>

using namespace std;

int main()
{
    char *expression = new char[size];
    cout << "Enter your math expression(in normal notation): " << endl;
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            expression[i] = c;
            i++;
        }
    }
    Calculator *calculator = new Calculator(expression, i);
    cout << calculator->countUp() << endl;
    return 0;
}
