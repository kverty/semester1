#pragma once

const int size = 100;

struct StackElement
{
    char value;
    StackElement *next;
};


struct Stack
{
    StackElement *top;
};

Stack *createStack();
void push(Stack *stack, char value);
char pop(Stack *stack);
void deleteTop(Stack *stack);
char top(Stack *stack);
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);

