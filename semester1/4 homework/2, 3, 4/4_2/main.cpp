#include <iostream>
#include "expressions.h"
#include "stack.h"
#include <string.h>

using namespace std;

int main()
{
    char normalExpression[size];
    cout << "Enter your math expressionin normal form:" << endl;
    scanf("%s", &normalExpression);
    int length = strlen(normalExpression);
    cout << "Result : " << normalToAnswer(normalExpression, length) << endl;
    return 0;
}

