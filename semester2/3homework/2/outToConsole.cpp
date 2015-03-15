#include "output.h"
#include "outToConsole.h"
#include <iostream>

using namespace std;

ConsoleOutput::ConsoleOutput(int **matrix, int length) : matrix(matrix), length(length)
{

}

void ConsoleOutput::out()
{
    int *array = squareToLinear(matrix, length);
    for (int i = 0; i < length * length; i++)
        cout << array[i] << " ";
    delete[] array;
}
