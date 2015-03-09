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
    //cout << "lol";
    Token *polishExpression[size];
    Stack *stack = new SimpleStack();
    int j = 0;
    int i = 0;

    while(i < length)
    {
        //cout << expression[i];
        if (isDigit(expression[i]))
        {
            int newNumber = getNextNumber(expression, length, i);
            //cout << newNumber << endl;
            polishExpression[j] = new Token(newNumber, number);
            j++;
            i--;
        }
        if ((expression[i] == '*') || (expression[i] == '/'))
        {
            while((!stack->length() == 0) && ((stack->top()->type() == mult) || (stack->top()->type() == division)))
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
            if ((!stack->length() == 0) && (stack->top()->type() != openBracket))
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

    while (!stack->length() == 0)
    {
        polishExpression[j] = stack->pop();
        j++;
    }
    //for (int k = 0; k < j; k++)
    //    cout << polishExpression[k]->number() << " ";
    return polishToAnswer(polishExpression, j);
}
