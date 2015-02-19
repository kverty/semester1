#include <iostream>
#include <string.h>
#include <stdio.h>
#include "stack.h"
//#include "expressions.h"

using namespace std;

int polishToAnswer(Stack *polishExpressionInStack)
{
    char polishExpression[size] = {'\0'};
    int length = 0;

    while (!isEmpty(polishExpressionInStack))
    {
        polishExpression[length] = pop(polishExpressionInStack);
        length++;
    }
    Stack *stack = createStack();
    for (int i = 0; i < length; i++)
    {
        if ((polishExpression[i] - '0' >= 0) && (polishExpression[i] - '0' <= 9))
        {
            push(stack, polishExpression[i]);
        }
        if (polishExpression[i] == '+')
        {
            push(stack, ((pop(stack) - '0') + (pop(stack) - '0') + '0'));
        }
        if (polishExpression[i] == '*')
        {
            push(stack, ((pop(stack) - '0') * (pop(stack) - '0') + '0'));
        }
        if (polishExpression[i] == '-')
        {
            push(stack, ((pop(stack) - '0') - (pop(stack) - '0') + '0'));
        }
        if (polishExpression[i] == '/')
        {
            push(stack, ((pop(stack) - '0') / (pop(stack) - '0') + '0'));
        }
    }
    int result = pop(stack) - '0';

    deleteStack(stack);
    return result;
}


Stack *normalToPolish()
{
    char normalExpression[size];
    char polishExpression[size] = {'\0'};

    Stack *stack = createStack();
    Stack *polishExpressionInStack = createStack();

    cout << "Enter your math expressionin normal form:" << endl;
    scanf("%s", &normalExpression);

    int j = 0;
    int length = strlen(normalExpression);

    for (int i = 0; i < length;i++)
    {
        if ((normalExpression[i] - '0' >= 0)&&(normalExpression[i] - '0' <= 9))
        {
            polishExpression[j] = normalExpression[i];
            j++;
        }
        if ((normalExpression[i] == '*')||(normalExpression[i] == '/'))
        {
            while((!isEmpty(stack)) && ((top(stack) == '*') || (top(stack) == '/')))
            {
                polishExpression[j] = pop(stack);
                j++;
            }
            push(stack, normalExpression[i]);
        }
        if ((normalExpression[i] == '+')||(normalExpression[i] == '-'))
        {
            if ((!isEmpty(stack))&&(top(stack) != '('))
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
            char x = pop(stack);
        }
    }

    while (!isEmpty(stack))
    {
        polishExpression[j] = pop(stack);
        j++;
    }
    for (int i = j - 1; i >= 0; i--)
    {
        push(polishExpressionInStack, polishExpression[i]);
    }
    deleteStack(stack);
    return polishExpressionInStack;
}
