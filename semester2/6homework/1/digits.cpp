#include "digits.h"


int charToInt(char c)
{
    return c - '0';
}

char intToChar(int c)
{
    return c + '0';
}

bool isDigit(char c)
{
    return (charToInt(c) >= 0) && (charToInt(c) <= 9);
}


bool isOperation(char c)
{
    return (c == '*') || (c == '/') || (c == '+') || (c == '-');
}

int readNumber(FILE *file, int startValue)
{
    int newValue = startValue;
    while (true)
    {
        char symbol;
        fscanf(file, "%c", &symbol);
        if (!isDigit(symbol))
            break;
        newValue = newValue * 10 + (symbol - '0');
    }
    return newValue;
}
