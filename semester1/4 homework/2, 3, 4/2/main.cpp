#include <iostream>
#include "stack.h"
#include "digits.h"
#include <string.h>

using namespace std;

int main()
{
    char normalExpression[size];
    Stack *stack = createStack();

    cout << "Enter your math expression : " << endl;
    scanf("%s", &normalExpression);

    int length = strlen(normalExpression);
    for (int i = 0; i < length;i++)
    {
        if (isDigit(normalExpression[i]))
        {
            cout << normalExpression[i];
        }
        if ((normalExpression[i] == '*') || (normalExpression[i] == '/'))
        {
            while((!isEmpty(stack)) && ((top(stack) == '*') || (top(stack) == '/')))
            {
                cout << pop(stack);
            }
            push(stack, normalExpression[i]);
        }
        if ((normalExpression[i] == '+') || (normalExpression[i] == '-'))
        {
            if ((!isEmpty(stack)) && (top(stack) != '('))
                cout << pop(stack);
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
                cout << pop(stack);
            }
            pop(stack);
        }
    }

    while (!isEmpty(stack))
    {
        cout << pop(stack);
    }
    deleteStack(stack);
    return 0;
}

