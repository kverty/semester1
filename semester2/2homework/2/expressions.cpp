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


Token::Token(int number, TokenType type) : numbe(number), type(type)
{

}

Token::~Token()
{

}

int Token::mNumber()
{
    return numbe;
}

TokenType Token::mType()
{
    return type;
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
        if (polishExpression[i]->mType() == number)
        {
           stack->push(polishExpression[i]);
        }
        if (polishExpression[i]->mType() == pluss)
        {
            stack->push(new Token(stack->pop()->mNumber() + stack->pop()->mNumber(), number));
        }
        if (polishExpression[i]->mType() == mult)
        {
            stack->push(new Token(stack->pop()->mNumber() * stack->pop()->mNumber(), number));
        }
        if (polishExpression[i]->mType() == minuss)
        {
            int second = stack->pop()->mNumber();
            int first = stack->pop()->mNumber();
            stack->push(new Token(first - second, number));
        }
        if (polishExpression[i]->mType() == division)
        {
            int second = stack->pop()->mNumber();
            int first = stack->pop()->mNumber();
            stack->push(new Token(first / second, number));
        }
    }
    int result = stack->pop()->mNumber();

    return result;
}


