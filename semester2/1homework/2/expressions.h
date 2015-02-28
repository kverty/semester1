#pragma once

const int size = 100;

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

int getNextNumber(char expression[size], int length, int &index);

class Token
{
public:
    Token(int number, TokenType type);
    ~Token();
    int number();
    TokenType type();
private:
    int numbe;
    TokenType typ;
};

int polishToAnswer(Token *polishExpression[size], int length);
