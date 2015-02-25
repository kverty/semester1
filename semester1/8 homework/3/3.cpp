#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSizeOfName = 100;

void dfs(int vertex, bool *matrix, int* &isVisited, int numberOfComponent, int numberOfVertexes)
{
    for (int i = 0; i < numberOfVertexes; i++)
    {
        if ((matrix[numberOfVertexes * vertex + i]) && (isVisited[i] == 0))
        {
            isVisited[i] = numberOfComponent;
            dfs(i, matrix, isVisited, numberOfComponent, numberOfVertexes);
        }
    }
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
        bool *matrix = new bool[n * n];
        int *isVisited = new int[n];

        for (int i = 0; i < n; i++)
            isVisited[i] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int x = 0;
                fscanf(file, "%d", &x);
                matrix[i * n + j] = (x == 1);
            }
        fclose(file);


        int numberOfComponent = 0;
        for (int i = 0; i < n; i++)
        {
            if (isVisited[i] == 0)
            {
                numberOfComponent++;
                isVisited[i] = numberOfComponent;
                dfs(i, matrix, isVisited, numberOfComponent, n);
            }
        }

        /*for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", matrix[i * n + j]);
            cout << endl;
        }
        cout << endl;
        */
        for (int i = 0; i < n; i++)
            cout << isVisited[i] << " ";
    }
    return 0;
}
