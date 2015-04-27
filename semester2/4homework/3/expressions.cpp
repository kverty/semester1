#include "expressions.h"

bool isOperation(QChar c)
{
    return (c == '=' || c == '+' || c == '-' || c == '*' || c == '/');
}

bool isDigit(char c)
{
    return (c - '0' >= 0 && c - '0' <= 9);
}
