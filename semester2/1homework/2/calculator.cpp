#include <iostream>
#include "stack.h"
#include "simpleStack.h"
#include "arrayStack.h"
#include "calculator.h"

using namespace std;

Calculator::Calculator(char *expression, int length) : expression(expression), length(length)
{

}

Calculator::~Calculator()
{
    delete[] expression;
}

int charToInt(char c)
{
    return c - '0';
}

int intToChar(int c)
{
    return c + '0';
}

bool isDigit(char c)
{
    return (charToInt(c) >= 0) && (charToInt(c) <= 9);
}

int getNextNumber(char *expression, int &index)
{
    int answer = 0;
    while (isDigit(expression[index]))
    {
        answer = answer * 10 + charToInt(expression[index]);
        index++;
    }
    return answer;
}

int Calculator::countUp()
{
    Stack *stack = new ArrayStack();
    int i = 0;
    while(i < length)
    {
        if (expression[i] == '+')
        {
            stack->push(intToChar(charToInt(stack->pop()) + charToInt(stack->pop())));
        }
        else if (expression[i] == '*')
        {
            stack->push(intToChar(charToInt(stack->pop()) * charToInt(stack->pop())));
        }
        else if (expression[i] == '-')
        {
            int second = charToInt(stack->pop());
            int first = charToInt(stack->pop());
            stack->push(intToChar(first - second));
        }
        else if (expression[i] == '/')
        {
            int second = charToInt(stack->pop());
            int first = charToInt(stack->pop());
            stack->push(intToChar(first / second));
        }
        else
        {
            stack->push(expression[i]);
        }
        i++;
    }
    return charToInt(stack->pop());
}
