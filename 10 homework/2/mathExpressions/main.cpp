#include <iostream>
#include <string.h>
//#include "list.h"
#include "mathExpressions.h"
#include <stdio.h>

using namespace std;
const int maxLength = 100;


int main()
{
    cout << "Please, enter your expression : " << endl;
    char line[maxLength];
    gets(line);
    Token *tokens = expressionToTokens(line, strlen(line));
    if (tokens != nullptr)
    {
        int numberOfTokens = 0;
        while(tokens[numberOfTokens] != null)
        {
            printToken(tokens[numberOfTokens]);
            numberOfTokens++;
        }

        //printList(tokens);
        if (isCorrect(tokens, 0, numberOfTokens - 1))
            cout << "Expression is correct!" << endl;
        else
            cout << "Expression is not correct!" << endl;
    }
    delete[] tokens;
    return 0;
}

