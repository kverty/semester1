#include "expressions.h"
#include "stack.h"
#include "simpleStack.h"

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


Token::Token(int number, TokenType type) : numbe(number), typ(type)
{

}

Token::~Token()
{

}

int Token::number()
{
    return numbe;
}

TokenType Token::type()
{
    return typ;
}

int mNextNumber(char expression[size], int length, int &index)
{
    int answer = 0;
    while (index < length && isDigit(expression[index]))
    {
        answer = answer * 10 + charToInt(expression[index]);
        index++;
    }
    return answer;
}

int polishToAnswer(Token *polishExpression[size], int length)
{
    Stack *stack = new SimpleStack();
    for (int i = 0; i < length; i++)
    {
        if (polishExpression[i]->type() == number)
        {
           stack->push(polishExpression[i]);
        }
        if (polishExpression[i]->type() == pluss)
        {
            stack->push(new Token(stack->pop()->number() + stack->pop()->number(), number));
        }
        if (polishExpression[i]->type() == mult)
        {
            stack->push(new Token(stack->pop()->number() * stack->pop()->number(), number));
        }
        if (polishExpression[i]->type() == minuss)
        {
            int second = stack->pop()->number();
            int first = stack->pop()->number();
            stack->push(new Token(first - second, number));
        }
        if (polishExpression[i]->type() == division)
        {
            int second = stack->pop()->number();
            int first = stack->pop()->number();
            stack->push(new Token(first / second, number));
        }
    }
    int result = stack->pop()->number();

    return result;
}


