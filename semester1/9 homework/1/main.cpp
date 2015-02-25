#include <cstdio>
#include <string.h>
#include <iostream>
#include "list.h"

using namespace std;

const int maxSizeOfName = 100;
const int maxSizeOfLine = 200;

int main()
{
    FILE* inFile = NULL;
    char filename[maxSizeOfName];

    cout << "Please, enter the name of first file: " << endl;

    scanf("%s", filename);
    inFile = fopen (filename,"r");
    List *stringsOfFile1 = createList();

    if (inFile == NULL)
    {
        cout << "There is no such file!" << endl;
        fclose(inFile);
        deleteList(stringsOfFile1);
        return 0;
    }
    else
    {
        char line[maxSizeOfLine];
        while (fgets(line, maxSizeOfLine, inFile) != NULL)
        {
            addValue(stringsOfFile1, line, strlen(line));
            //printf("%s", line);
        }
    }

    cout << "Please, enter the name of second file: " << endl;

    scanf("%s", filename);
    inFile = fopen (filename,"r");

    cout << "Please, enter the name of third file: " << endl;

    scanf("%s", filename);
    FILE *outFile = fopen (filename,"w");

    if (inFile == NULL)
    {
        cout << "There is no such file!" << endl;
        fclose(inFile);
        fclose(outFile);
        deleteList(stringsOfFile1);
        return 0;
    }
    else
    {
        char line[maxSizeOfLine];
        while (fgets(line, maxSizeOfLine, inFile) != NULL)
        {
            if (wasFound(stringsOfFile1, line, strlen(line)))
                fprintf(outFile, "%s", line);
        }
    }

    fclose(inFile);
    fclose(outFile);
    deleteList(stringsOfFile1);
    return 0;
}
