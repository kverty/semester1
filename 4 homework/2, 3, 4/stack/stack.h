#pragma once

struct StackElement
{
    int value;
    StackElement *next;
};


struct Stack
{
    StackElement *top;
};

Stack *createStack();
void push(Stack *stack, int value);
int pop(Stack *stack);
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);

