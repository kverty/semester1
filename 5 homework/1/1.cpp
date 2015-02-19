#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxIdOfLetter = 100;
const int maxSizeOfName = 100;

int printRightWordAndReturnEnd(char *line, int start)
{
    bool letterWasUsed[maxIdOfLetter];
    int length = strlen(line);
    for (int j = 0; j < maxIdOfLetter; j++)
        letterWasUsed[j] = false;

    letterWasUsed['\n' - '0'] = true;

    int current = start;
    while ((current < length) && (line[current] != ' '))
    {
        if (!letterWasUsed[line[current] - '0'])
        {
            cout << line[current];
            letterWasUsed[line[current] - '0'] = true;
        }
        current++;
    }
    cout << ' ';
    return current;
}

void printStringInRightForm(char *line)
{
    int length = strlen(line);
    int i = 0;
    while (i < length)
    {
        if (line[i] == ' ')
            i++;
        else
            i = printRightWordAndReturnEnd(line, i);
    }
    cout << endl;
}

int main()
{
    char filename[maxSizeOfName];

    cout << "Please, enter name of the file: " << endl;
    scanf("%s", filename);
    FILE * file = fopen(filename,"r");

    if (file == NULL)
    {
        cout << "There is no such file!" << endl;
        fclose(file);
        return 0;
    }

    char line[100];
    cout << "All the words in right form :" << endl;
    while (fgets(line, 100, file) != NULL)
    {
        printStringInRightForm(line);
    }

    fclose(file);
    return 0;
}
