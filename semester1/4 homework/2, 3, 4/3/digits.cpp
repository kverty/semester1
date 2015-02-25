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
