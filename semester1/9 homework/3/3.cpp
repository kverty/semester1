#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSizeOfName = 100;

int *primSpanningTree(int *matrix, int n)
{
    bool *wasAdded = new bool[n];

    for (int i = 0; i < n; i++)
        wasAdded[i] = false;

    wasAdded[0] = true;

}

int main()
{
    FILE * file = NULL;
    char filename[maxSizeOfName];

    cout << "Please, enter the name of the file with the number of vertexes and matrix : " << endl;

    scanf("%s", filename);
    file = fopen (filename,"r");

    if (file == NULL)
    {
        cout << "There is no such file!" << endl;
        fclose (file);
        return 0;
    }
    else
    {
        int n = 0;
        fscanf(file, "%d", &n);

        int *matrix = new int[n * n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int x = 0;
                fscanf(file, "%d", &x);
                addValue(edges[i], j);
            }
        fclose(file);

        int *newMatrix = primSpanningTree(matrix, n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d " newMatrix[i * n + j]);
            printf("\n");
        }
    }
    return 0;
}
