#pragma once
#include "output.h"

///interface to print array of number to File
class FileOutput : public Output
{
public:
    FileOutput(char* filename, int **matrix, int length);
    void out();

private:
    char *filename;
    int **matrix;
    int length;
};
