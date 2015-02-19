#include <stdio.h>
#include <iostream>
#include <string.h>
#include "mathExpressions.h"

using namespace std;

enum CharType
{
    space,
    newLine,
    endLine,
    point,
    digit,
    plusOrMinus,
    charE,
    sthStrange,
    divOrMult,
    openBracket,
    closeBracket
};

enum State
{
    notStarted,
    noSign,
    sign,
    integerPart,
    dot,
    fractPart,
    letterE,
    signAfterE,
    integerAfterE,
    error,
    theEnd
};

void printToken(Token value)
{
    switch(value)
    {
        case id:
            cout << "id ";
            break;
        case multiplication:
            cout << "*/ ";
            break;
        case addition:
            cout << "+- ";
            break;
        case closingBracket:
            cout << ") ";
            break;
        case openingBracket:
            cout << "( ";
            break;
        default:
            break;
    }
}

CharType returnType(char c)
{
    if (c == ' ')
        return space;
    if (c == '\n')
        return newLine;
    if (c == '\0')
        return endLine;
    if (c == '.')
        return point;
    if (c - '0' >= 0 && c - '0' < 10)
        return digit;
    if (c == '+' || c == '-')
        return plusOrMinus;
    if (c == '*' || c == '/')
        return divOrMult;
    if (c == ')')
        return closeBracket;
    if (c == '(')
        return openBracket;
    if (c == 'E' || c == 'e')
        return charE;
    return sthStrange;
}

const int maxLength = 100;

void writeState(State state)
{
    switch(state)
    {
        case notStarted:
            cout << "notStarted\n";
            break;
        case sign:
            cout << "sign\n";
            break;
        case noSign:
            cout << "noSign\n";
            break;
        case integerPart:
            cout << "integerPart\n";
            break;
        case dot:
            cout << "dot\n";
            break;
        case fractPart:
            cout << "fractPart\n";
            break;
        case letterE:
            cout << "letterE\n";
            break;
        case signAfterE:
            cout << "signAfterE\n";
            break;
        case integerAfterE:
            cout << "integerAfterE\n";
            break;
        case error:
            cout << "error\n";
            break;
        case theEnd:
            cout << "theEnd\n";
            break;
    }
}

void writeType(CharType type)
{
    switch(type)
    {
        case space:
            cout << "space\n";
            break;
        case newLine:
            cout << "newLine\n";
            break;
        case endLine:
            cout << "endLine\n";
            break;
        case point:
            cout << "dot\n";
            break;
        case digit:
            cout << "digit\n";
            break;
        case plusOrMinus:
            cout << "sign\n";
            break;
        case divOrMult:
            cout << "divOrMult\n";
            break;
        case closeBracket:
            cout << "closeBracket\n";
            break;
        case openBracket:
            cout << "openBracket\n";
            break;
        case charE :
            cout << "charE\n";
            break;
        case sthStrange:
            cout << "sthStrange\n";
            break;
    }
}

Token *expressionToTokens(char *line, int length)
{
    //List *tokens = createList();
    int numberOfTokens = 0;
    Token *tokens = new Token[length + 1];
    for (int i = 0; i < length + 1; i++)
        tokens[i] = null;

    State state = notStarted;
    for (int i = 0; i < length; i++)
    {
        char newChar = line[i];
        //cout << i << ".) " << newChar << ' ';

        CharType type = returnType(newChar);
        //writeType(type);
        switch(type)
        {
            case space:
                switch(state)
                {
                    case dot:
                    case letterE:
                    case signAfterE:
                        state = error;
                        break;
                    case notStarted:
                    case noSign:
                    case sign:
                        break;
                    default:
                        //addValueQueue(tokens, id);
                        //addValue(tokens, id);
                        tokens[numberOfTokens] = id;
                        numberOfTokens++;
                        state = noSign;
                        break;
                }
                break;
            case newLine:
            case endLine:
                if (state == sign || state == dot || state == letterE ||state == signAfterE)
                    state = error;
                else
                    state = theEnd;
                break;
            case point:
                if (state == integerPart)
                    state = dot;
                else
                    state = error;
                break;
            case digit:
                switch(state)
                {
                    case noSign:
                        state = error;
                        break;
                    case notStarted:
                    case sign:
                        state = integerPart;
                        break;
                    case dot:
                        state = fractPart;
                        break;
                    case signAfterE:
                    case letterE:
                        state = integerAfterE;
                        break;
                    default:
                        break;
                }
                break;
            case plusOrMinus:
                switch(state)
                {
                    case sign:
                    case dot:
                    case signAfterE:
                        state = error;
                        break;
                    case integerPart:
                    case fractPart:
                    case integerAfterE:
                        //addValueQueue(tokens, id);
                        //addValue(tokens, id);
                        tokens[numberOfTokens] = id;
                        numberOfTokens++;
                        //addValueQueue(tokens, addition);
                        //addValue(tokens, addition);
                        tokens[numberOfTokens] = addition;
                        numberOfTokens++;
                        state = sign;
                        break;
                    case notStarted:
                    case noSign:
                        //addValueQueue(tokens, addition);
                        //addValue(tokens, addition);
                        tokens[numberOfTokens] = addition;
                        numberOfTokens++;
                        state = sign;
                        break;
                    case letterE:
                        state = signAfterE;
                        break;
                    default:
                        break;
                }
                break;
            case divOrMult:
                switch(state)
                {
                    case sign:
                    case dot:
                    case signAfterE:
                    case notStarted:
                    case letterE:
                        state = error;
                        break;
                    case integerPart:
                    case fractPart:
                    case integerAfterE:
                        //addValueQueue(tokens, id);
                        //addValue(tokens, id);
                        tokens[numberOfTokens] = id;
                        numberOfTokens++;
                        //addValueQueue(tokens, multiplication);
                        //addValue(tokens, multiplication);
                        tokens[numberOfTokens] = multiplication;
                        numberOfTokens++;
                        state = sign;
                        break;
                    case noSign:
                        //addValueQueue(tokens, multiplication);
                        //addValue(tokens, multiplication);
                        tokens[numberOfTokens] = multiplication;
                        numberOfTokens++;
                        state = sign;
                        break;
                    default:
                        break;
                }
                break;
            case openBracket:
            {
                switch(state)
                {
                    case dot:
                    case signAfterE:
                    case letterE:
                    case noSign:
                    case integerPart:
                    case fractPart:
                    case integerAfterE:
                        state = error;
                        break;
                    case sign:
                    case notStarted:
                        state = notStarted;
                        //addValueQueue(tokens, openingBracket);
                        //addValue(tokens, openingBracket);
                        tokens[numberOfTokens] = openingBracket;
                        numberOfTokens++;
                        break;
                    default:
                        break;
                }
                break;
            }
            case closeBracket:
            {
                switch(state)
                {
                    case dot:
                    case signAfterE:
                    case letterE:
                    case sign:
                        state = error;
                        break;
                    case notStarted:
                    case noSign:
                        state = notStarted;
                        //addValueQueue(tokens, closingBracket);
                        //addValue(tokens, closingBracket);
                        tokens[numberOfTokens] = closingBracket;
                        numberOfTokens++;
                        break;
                    case integerPart:
                    case fractPart:
                    case integerAfterE:
                        state = noSign;
                        //addValueQueue(tokens, id);
                        //addValue(tokens, id);
                        tokens[numberOfTokens] = id;
                        numberOfTokens++;
                        //addValueQueue(tokens, closingBracket);
                        //addValue(tokens, closingBracket);
                        tokens[numberOfTokens] = closingBracket;
                        numberOfTokens++;
                        break;
                    default:
                        break;
                }
                break;
            }
            case charE:
                if (state == fractPart || state == integerPart)
                    state = letterE;
                else
                    state = error;
                break;
            case sthStrange:
                state = error;
                break;
        }

        //writeState(state);

        if (state == error)
        {
            cout << "Wrong number\nSymbol '" << newChar << "' is incorrect";
            //writeType(type);
            return nullptr;
        }
        if (state == theEnd)
        {
            //cout << "It is correct!";
            return tokens;
        }
        //printList(tokens);
        //cout << endl << endl;
        if (i == length - 1 && (state == integerPart || state ==  fractPart || state == integerAfterE))
        {
            //addValueQueue(tokens, id);
            //addValue(tokens, id);
            tokens[numberOfTokens] = id;
            numberOfTokens++;
        }
    }
    //cout << "It is correct!" << endl;
    return tokens;
}



bool isCorrect(Token *tokens, int start, int finish)
{
    if (start > finish)
        return false;

    if (start == finish)
    {
        return (tokens[start] == id);
    }
    if (tokens[start] == addition && tokens[start + 1] != addition)
        if (isCorrect(tokens, start + 1, finish))
            return true;

    if (tokens[finish] == closingBracket && tokens[start] == openingBracket)
        if (isCorrect(tokens, start + 1, finish - 1))
            return true;

    for (int i = finish; i >= start; i--)
        if (tokens[i] == addition)
            if (isCorrect(tokens, start, i - 1) && isCorrect(tokens, i + 1, finish))
                return true;

    for (int i = finish; i >= start; i--)
        if (tokens[i] == multiplication)
            if (isCorrect(tokens, start, i - 1) && isCorrect(tokens, i + 1, finish))
                return true;

    return false;
}
