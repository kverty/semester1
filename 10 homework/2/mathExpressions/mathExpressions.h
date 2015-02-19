#pragma once
//#include "list.h"

enum Token
{
    id,
    addition,
    multiplication,
    openingBracket,
    closingBracket,
    null
};

void printToken(Token value);
Token *expressionToTokens(char *line, int length);
bool isCorrect(Token *tokens, int start, int end);
