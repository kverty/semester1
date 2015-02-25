#include <iostream>
#include "stack.h"

using namespace std;

bool test1()
{
    Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    int x = pop(stack);
    int y = pop(stack);
    deleteStack(stack);
    return (x == 2) && (y == 1);
}

int main()
{
    if (test1())
        printf("OK\n");
    else
        printf("Not OK\n");

    return 0;
}

