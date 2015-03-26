#include <iostream>
#include "stack.h"
#include "simpleStack.h"
#include "calculator.h"
#include "expressions.h"

using namespace std;

Calculator::Calculator(char *expression, int length) : expression(expression), length(length)
{

}

Calculator::~Calculator()
{
    delete[] expression;
}


int Calculator::countUp()
{
    Token *polishExpression[size];
    Stack *stack = new SimpleStack();
    int j = 0;
    int i = 0;

    while(i < length)
    {
        if (isDigit(expression[i]))
        {
            int newNumber = mNextNumber(expression, length, i);
            polishExpression[j] = new Token(newNumber, number);
            j++;
            i--;
        }
        if ((expression[i] == '*') || (expression[i] == '/'))
        {
            while((!stack->mLength() == 0) && ((stack->top()->type() == mult) || (stack->top()->type() == division)))
            {
                polishExpression[j] = stack->pop();
                j++;
            }

            TokenType type = mult;
            if (expression[i] == '/')
                type = division;
            stack->push(new Token(charToInt(expression[i]), type));
        }

        if ((expression[i] == '+') || (expression[i] == '-'))
        {
            if ((!stack->mLength() == 0) && (stack->top()->type() != openBracket))
            {
                polishExpression[j] = stack->pop();
                j++;
            }
            TokenType type = minuss;
            if (expression[i] == '+')
                type = pluss;
            stack->push(new Token(charToInt(expression[i]), type));
        }
        if (expression[i] == '(')
        {
            stack->push(new Token(charToInt(expression[i]), openBracket));
        }
        if (expression[i] == ')')
        {
            while(stack->top()->type() != openBracket)
            {
                polishExpression[j] = stack->pop();
                j++;
            }
            stack->pop();
        }
        i++;
    }

    while (!stack->mLength() == 0)
    {
        polishExpression[j] = stack->pop();
        j++;
    }

    return polishToAnswer(polishExpression, j);
}
