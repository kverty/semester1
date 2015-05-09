#pragma once

const int size = 100;

///some useful functions
int charToInt(char c);
int intToChar(int c);

bool isDigit(char c);

enum TokenType
{
    pluss,
    minuss,
    mult,
    division,
    number,
    openBracket,
    closeBracket
};

///function to find next number is array of chars from ith position
int mNextNumber(char expression[size], int length, int &index);

///Token = operation or operator, depends on type; number = value of Token if it is number
class Token
{
public:
    Token(int number, TokenType type);
    ~Token();
    int mNumber();
    TokenType mType();
private:
    int numbe;
    TokenType type;
};

int polishToAnswer(Token *polishExpression[size], int length);
