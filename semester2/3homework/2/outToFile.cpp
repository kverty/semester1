#include "output.h"
#include "outToFile.h"
#include <cstdio>

FileOutput::FileOutput(char* filename, int **matrix, int length) : filename(filename), matrix(matrix), length(length)
{

}

void FileOutput::out()
{
    FILE *outFile = fopen (filename, "w");
    int *array = squareToLinear(matrix, length);

    for (int i = 0; i < length * length; i++)
    {
        fprintf(outFile, "%d ", array[i]);
    }

    fclose(outFile);
    delete outFile;
    delete[] array;
}
