#include "output.h"
#include "outToFile.h"
#include <cstdio>

FileOutput::FileOutput(char* filename, int *array, int length) : filename(filename), array(array), length(length)
{

}

void FileOutput::out()
{
    FILE *outFile = fopen (filename, "w");

    for (int i = 0; i < length; i++)
    {
        fprintf(outFile, "%d ", array[i]);
    }

    fclose(outFile);
    delete outFile;
}
