#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSizeOfName = 100;

int main ()
{
    FILE * file;
    char filename[maxSizeOfName];

    cout << "Please, enter name of the file: " << endl;
    scanf("%s", filename);
    file = fopen (filename,"r");

    if (file==NULL)
    {
        cout << "There is no such file!" << endl;
        fclose (file);
        return 0;
    }
    else
    {
        char line[100];
        bool bigCommentIsOpen = false;

        cout << "All the comments: " << endl;
        while (fgets(line, 100, file) != NULL)
        {
            bool isCommented = false;
            int length = strlen(line);
            bool quoteIsOpen = false;
            bool doubleQuoteIsOpen = false;
            int i = 0;

            while (i < length - 1)
            {
                if (isCommented)
                    cout << line[i];
                else
                {
                    if ((line[i] == '/') && (line[i + 1] == '*') && !doubleQuoteIsOpen && !quoteIsOpen && !bigCommentIsOpen)
                    {
                        bigCommentIsOpen = true;
                        i += 2;
                        continue;
                    }
                    if ((line[i] == '*') && (line[i + 1] == '/'))
                    {
                        bigCommentIsOpen = false;
                        i += 2;
                         continue;
                    }

                    if ((line[i] == '/') && (line[i + 1] == '/') && !quoteIsOpen && !bigCommentIsOpen && !doubleQuoteIsOpen)
                    {
                        isCommented = true;
                        cout << "//";
                        i += 2;
                        continue;
                    }

                    if ((line[i] == '"') && (i == 0) && !bigCommentIsOpen)
                        doubleQuoteIsOpen = !doubleQuoteIsOpen;
                    if ((i > 0) && (line[i] == '"') && (line[i - 1] != '\\') && !bigCommentIsOpen && !quoteIsOpen)
                        doubleQuoteIsOpen = !doubleQuoteIsOpen;

                    if ((line[i] == '\'') && (i == 0) && !bigCommentIsOpen)
                        quoteIsOpen = !quoteIsOpen;
                    if ((i > 0) && (line[i] == '\'') && (line[i - 1] != '\\') && !bigCommentIsOpen && !doubleQuoteIsOpen)
                        quoteIsOpen = !quoteIsOpen;
                }
                i++;
            }
            if (isCommented)
                    cout << line[length - 1];
        }
    }
    return 0;
}
