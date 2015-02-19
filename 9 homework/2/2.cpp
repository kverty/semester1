#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int prime = 101;
const int module = 131;
const int maxSizeOfLine = 500;

int main()
{
    char line[maxSizeOfLine];
    char temp[maxSizeOfLine];
    //char *line;
    //char *temp;

    cout << "Enter the string :\n";
    scanf("%s", line);
    //gets(line);

    cout << "Enter the template :\n";
    scanf("%s", temp);
    //gets(temp);

    int linesHash = 0;
    int tempHash = 0;
    int primesPow = 1;

    for (int i = strlen(temp) - 1; i >= 0; i--)
    {
        primesPow = primesPow % module;
        linesHash = (linesHash + primesPow * (line[i] - '0')) % module;
        tempHash = (tempHash + primesPow * (temp[i] - '0')) % module;
        primesPow = primesPow * prime;
    }
    primesPow = primesPow / prime;

    bool wasFound = false;

    for (int i = 0; i < strlen(line) - strlen(temp) + 1; i++)
    {
        /*
        printf("%s % d\n", line, linesHash);
        for (int j = 0; j < i; j++)
            cout << " ";
        printf("%s %d\n", temp, tempHash);
        */

        if (tempHash == linesHash)
        {
            bool isEqual = true;
            for (int j = 0; j < strlen(temp); j++)
                if (temp[j] != line[i + j])
                    isEqual = false;

            if (isEqual)
            {
                cout << "first position of template: " << i + 1 << endl;
                wasFound = true;
            }
        }

        linesHash = (linesHash - (line[i] - '0') * primesPow) % module;
        linesHash = ((linesHash * prime) % module + module) % module;
        if (i + strlen(temp) < strlen(line))
            linesHash = (linesHash + (line[i + strlen(temp)] - '0')) % module;
    }

    if (!wasFound)
        cout << "No\n";
    return 0;
}
