#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSizeOfName = 100;

void dfs(int vertex, bool *matrix, int* &isVisited, int numberOfVertexes)
{
    for (int i = 0; i < numberOfVertexes; i++)
    {
        if ((matrix[numberOfVertexes * vertex + i]) && (isVisited[i] == 0))
        {
            isVisited[i] = isVisited[vertex];
            dfs(i, matrix, isVisited, numberOfVertexes);
        }
    }
}


int main()
{
    FILE * file = NULL;
    char filename[maxSizeOfName];

    cout << "Please, enter the name of the file with list of edges: " << endl;

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
        int m = 0;

        fscanf(file, "%d %d", &n, &m);
        bool *matrix = new bool[n * n];
        int *isVisited = new int[n];

        for (int i = 0; i < n; i++)
        {
            isVisited[i] = 0;
            for (int j = 0; j < n; j++)
                matrix[i * n + j] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int x = 0;
            int y = 0;
            fscanf(file, "%d %d", &x, &y);
            matrix[(y - 1) * n + (x - 1)] = true;
            matrix[(x - 1) * n + (y - 1)] = true;
        }
        fclose(file);

        isVisited[0] = 1;
        isVisited[1] = 2;
        isVisited[2] = 3;

        dfs(0, matrix, isVisited, n);
        dfs(1, matrix, isVisited, n);
        dfs(2, matrix, isVisited, n);

        bool sbHasToBeExiled = false;

        for (int i = 3; i < n; i++)
            if (isVisited[i] > 0)
                cout << i + 1 << " " << isVisited[i] << endl;
            else
                sbHasToBeExiled = true;
        if (sbHasToBeExiled)
        {
            cout << "People that should be sent out : ";
            for (int i = 0; i < n; i++)
                if (isVisited[i] == 0)
                    cout << i + 1 << " ";
        }
    }
    return 0;
}
