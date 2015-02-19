#include <iostream>
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "expressions.h"
#include "digits.h"

using namespace std;

int polishToAnswer(char polishExpression[size], int length)
{
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
    int result = charToInt(pop(stack));

    deleteStack(stack);
    return result;
}


int normalToAnswer(char normalExpression[size], int length)
{
    char polishExpression[size];
    Stack *stack = createStack();
    int j = 0;

    for (int i = 0; i < length;i++)
    {
        if (isDigit(normalExpression[i]))
        {
            polishExpression[j] = normalExpression[i];
            j++;
        }
        if ((normalExpression[i] == '*') || (normalExpression[i] == '/'))
        {
            while((!isEmpty(stack)) && ((top(stack) == '*') || (top(stack) == '/')))
            {
                polishExpression[j] = pop(stack);
                j++;
            }
            push(stack, normalExpression[i]);
        }
        if ((normalExpression[i] == '+') || (normalExpression[i] == '-'))
        {
            if ((!isEmpty(stack)) && (top(stack) != '('))
            {
                polishExpression[j] = pop(stack);
                j++;
            }
            push(stack, normalExpression[i]);
        }
        if (normalExpression[i] == '(')
        {
            push(stack, normalExpression[i]);
        }
        if (normalExpression[i] == ')')
        {
            while(top(stack) != '(')
            {
                polishExpression[j] = pop(stack);
                j++;
            }
            deleteTop(stack);
        }
    }

    while (!isEmpty(stack))
    {
        polishExpression[j] = pop(stack);
        j++;
    }
    deleteStack(stack);
    int result = polishToAnswer(polishExpression, j);
    return result;
}
