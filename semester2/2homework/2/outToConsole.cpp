#include "output.h"
#include "outToConsole.h"
#include <iostream>

using namespace std;

ConsoleOutput::ConsoleOutput(int *array, int length) : array(array), length(length)
{

}

void ConsoleOutput::out()
{
    for (int i = 0; i < length; i++)
        cout << array[i] << " ";
}
