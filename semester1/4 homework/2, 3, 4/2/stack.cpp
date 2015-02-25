#include "stack.h"


/*bool isDigit(char c)
{
    return (c - '0' >= 0) && (c - '0' <= 9);
}*/

StackElement *createStackElement(char value, StackElement *next)
{
    StackElement *newStackElement = new StackElement;
    newStackElement->next = next;
    newStackElement->value = value;
    return newStackElement;
}


Stack *createStack()
{
    Stack *newStack = new Stack;
    newStack->top = createStackElement(0, nullptr);
    return newStack;
}


void push(Stack *stack, char value)
{
    StackElement *newElement = createStackElement(value, stack->top->next);
    stack->top->next = newElement;
}


char pop(Stack *stack)
{
    char result = stack->top->next->value;
    StackElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete element;
    return result;
}

bool isEmpty(Stack *stack)
{
    return stack->top->next == nullptr;
}

void deleteStack(Stack *stack)
{
    while (!isEmpty(stack))
        pop(stack);
    delete stack->top;
    delete stack;
}

char top(Stack *stack)
{
    return stack->top->next->value;
}

/*void deleteTop(Stack *stack)
{
    StackElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete element;
}*/
