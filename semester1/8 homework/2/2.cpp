#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSizeOfName = 100;
const int inf = 1000000;

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
        int *matrix = new int[n * n];
        bool *visited = new bool[n];
        int *previousInThePath = new int[n];
        int *shortestWay = new int[n];
        int *orderOfAttack = new int[n];

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            previousInThePath[i] = -1;
            shortestWay[i] = inf;

            for (int j = 0; j < n; j++)
                matrix[i * n + j] = 0;
        }

        shortestWay[0] = 0;

        for (int i = 0; i < m; i++)
        {
            int x = 0;
            int y = 0;
            int length = 0;

            fscanf(file, "%d %d %d", &x, &y, &length);
            matrix[(x - 1) * n + (y - 1)] = length;
            matrix[(y - 1) * n + (x - 1)] = length;
        }
        fclose(file);

        for (int i = 0; i < n; i++)
        {
            int closestVertex = 0;
            int minPath = inf + 1;
            for (int j = 0; j < n; j++)
            {
                if ((shortestWay[j] < minPath) && (!visited[j]))
                {
                    minPath = shortestWay[j];
                    closestVertex = j;
                }
            }

            visited[closestVertex] = true;
            orderOfAttack[i] = closestVertex;
            //cout << closestVertex << " " << shortestWay[closestVertex] << endl;

            for (int j = 0; j < n; j++)
            {
                if ((!visited[j]) && (matrix[closestVertex * n + j] > 0) &&
                    ((shortestWay[j] > matrix[closestVertex * n + j] + shortestWay[closestVertex]) || (shortestWay[j] == inf)))
                {
                    shortestWay[j] = matrix[closestVertex * n + j] + shortestWay[closestVertex];
                    previousInThePath[j] = closestVertex;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            int current = orderOfAttack[i];
            cout << "Number of a town : " << current + 1 << "; ";
            cout << "distance : " << shortestWay[current] << "; ";
            cout << "path : ";

            while (previousInThePath[current] >= 0)
            {
                cout << current + 1 << " ";
                current = previousInThePath[current];
            }
            cout << "1\n";
        }
    }
    return 0;
}
