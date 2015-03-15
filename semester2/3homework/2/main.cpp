#include <iostream>
#include "output.h"
#include "outToConsole.h"
#include "outToFile.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

const int maxSizeOfName = 100;

enum Command
{
    toFile = 1,
    toConsole = 2
};

int main()
{
    int n = 0;

    cout << "Please, enter the size of the matrix : " << endl;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Size of the matrix need to be odd!" << endl;
        return 0;
    }

    int **matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    cout << "Here is randomly filled matrix :" << endl;

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
            cout << matrix[i][j] << " ";
            if (matrix[i][j] < 10)
                cout << " ";
        }
        cout << endl;
    }

    int command;
    cout << "How do you want to spirally print this matrix - to file or to console? (1 or 2)" << endl;
    cin >> command;

    Output *output;

    if (command == toFile)
    {
        char filename[maxSizeOfName];
        cout << "Print filename, please : " << endl;
        scanf("%s", filename);

        output = new FileOutput(filename, matrix, n);
    }

    if (command == toConsole)
    {

        output = new ConsoleOutput(matrix, n);
    }

    output->out();

    for (int i = 0; i < n; i++)
    {
        delete matrix[i];
    }
    delete matrix;
}

