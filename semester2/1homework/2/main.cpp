#include <iostream>
#include "stack.h"
#include "simpleStack.h"
#include "arrayStack.h"
#include "calculator.h"
#include <string.h>

using namespace std;

const int size = 100;

int main()
{
    char polishExpression[size];
    cout << "Enter your math expression in Reverse Polish notation: " << endl;
    scanf("%s", &polishExpression);

    Calculator *calculator = new Calculator(polishExpression, strlen(polishExpression));
    cout << calculator->countUp();

    return 0;
}
