#pragma once

struct StackElement
{
    char value;
    StackElement *next;
};

const int size = 100;

struct Stack
{
    StackElement *top;
};

Stack *createStack();
void push(Stack *stack, char value);
char pop(Stack *stack);
char top(Stack *stack);
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);
Stack *normalToPolish();
int polishToAnswer(Stack *polishExpressionInStack);

