#pragma once
#include "output.h"

class FileOutput : public Output
{
public:
    FileOutput(char* filename, int *array, int length);
    void out();

private:
    char *filename;
    int *array;
    int length;
};
