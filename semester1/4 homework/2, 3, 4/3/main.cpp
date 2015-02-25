#include <iostream>
#include <string.h>
#include "stack.h"
#include "digits.h"

using namespace std;

int main()
{
    char polishExpression[size];
    cout << "Enter your math expression in Reverse Polish notation : " << endl;
    scanf("%s", &polishExpression);

    int length = strlen(polishExpression);
    Stack *stack = createStack();
    for (int i = 0; i < length; i++)
    {
        if (isDigit(polishExpression[i]))
        {
            push(stack, polishExpression[i]);
        }
        if (polishExpression[i] == '+')
        {
            push(stack, intToChar(charToInt(pop(stack)) + charToInt(pop(stack))));
        }
        if (polishExpression[i] == '*')
        {
            push(stack, intToChar(charToInt(pop(stack)) * charToInt(pop(stack))));
        }
        if (polishExpression[i] == '-')
        {
            int second = charToInt(pop(stack));
            int first = charToInt(pop(stack));
            push(stack, intToChar(first - second));
        }
        if (polishExpression[i] == '/')
        {
            int second = charToInt(pop(stack));
            int first = charToInt(pop(stack));
            push(stack, intToChar(first / second));
        }
    }

    cout << "Result: " << charToInt(pop(stack)) << endl;
    deleteStack(stack);
    return 0;
}

