#include <stdio.h>
#include <iostream>
#include <string.h>

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
    sthStrange
};

enum State
{
    notStarted,
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
        case charE :
            cout << "charE\n";
            break;
        case sthStrange:
            cout << "sthStrange\n";
            break;
    }
}

int main()
{
    State state = notStarted;
    char line[maxLength];
    cout << "Please, enter your number : " << endl;
    gets(line);
    for (int i = 0; i < strlen(line); i++)
    {
        char newChar = line[i];
        //cout << i << ".) " << newChar << ' ';

        CharType type = returnType(newChar);
        //writeType(type);
        switch(type)
        {
            case space:
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
                    case notStarted:
                        state = integerPart;
                        break;
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
                }
                break;
            case plusOrMinus:
                switch(state)
                {
                    case sign:
                    case dot:
                    case signAfterE:
                    case integerPart:
                    case fractPart:
                    case integerAfterE:
                        state = error;
                        break;
                    //case(integerPart || fractPart || integerAfterE) : state = error;
                    case notStarted:
                        state = sign;
                        break;
                    case letterE:
                        state = signAfterE;
                        break;
                }
                break;
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
            return 0;
        }
        if (state == theEnd)
        {
            cout << "It is correct!";
            return 0;
        }
    }
    if (state == letterE || state == dot || state == sign || state == signAfterE)
        cout << "Wrong number\nSymbol '" << line[strlen(line) - 1] << "' is incorrect";
    else
        cout << "It is correct!" << endl;
    return 0;
}
