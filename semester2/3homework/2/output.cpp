#include "output.h"
#include <iostream>

using namespace std;

int *Output::squareToLinear(int **matrix, int n)
{
    int *answer = new int[n * n];
    int index = 0;
    int x = (n - 1) / 2;
    int y = (n - 1) / 2;
    int round = 1;

    answer[index] = matrix[x][y];
    index++;

    while(round <= (n - 1) / 2)
    {
        x--;
        answer[index] = matrix[x][y];
        index++;
        for (int i = 0; i < 2*round - 1; i++)
        {
            y--;
            answer[index] = matrix[x][y];
            index++;
        }
        for (int i = 0; i < 2 * round; i++)
        {
            x++;
            answer[index] = matrix[x][y];
            index++;
        }
        for (int i = 0; i < 2 * round; i++)
        {
            y++;
            answer[index] = matrix[x][y];
            index++;
        }
        for (int i = 0; i < 2 * round; i++)
        {
            x--;
            answer[index] = matrix[x][y];
            index++;
        }
        round++;
    }

    return answer;
}

