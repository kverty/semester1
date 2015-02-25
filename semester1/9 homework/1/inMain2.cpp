#include <cstdio>
#include <string.h>
#include <iostream>
#include <list.h>

using namespace std;

const int maxSizeOfName = 100;

int *primSpanningTree(List* *edges, int n)
{
    int *added = new int[n];
    int *newMatrix = new int[n * n];

    for (int i = 0; i < n; i++)
    {
        added[i] = 0;
        for (int j = 0; j < n; j++)
            newMatrix[i + j * n] = 0;
    }

    added[0] = 0;
    int numberOfAdded = 1;
    int minEdgeStart = 0;

    while (numberOfAdded < n)
    {
        for (int i = 0; i < n; i++)
            if (!isEmpty(edges[added[i]]))
            {
                minEdgeStart = added[i];
            }
        //for (int i = 0; i < n; i++)
            //printList(edges[i]);
        for (int i = 0; i < numberOfAdded; i++)
        {
            if (!isEmpty(edges[added[i]]))
                if (returnMinWeight(edges[added[i]]) < returnMinWeight(edges[minEdgeStart]))
                    minEdgeStart = added[i];
        }

        int minEdgeEnd = returnNearest(edges[minEdgeStart]);
        added[numberOfAdded] = minEdgeEnd;
        newMatrix[minEdgeStart + n * minEdgeEnd] = returnMinWeight(edges[minEdgeStart]);
        newMatrix[minEdgeStart * n + minEdgeEnd] = returnMinWeight(edges[minEdgeStart]);
        //cout << "newly added edge : " << minEdgeStart << " " << minEdgeEnd << endl;

        for (int i = 0; i < numberOfAdded; i++)
        {
            isolateVertex(edges[added[i]], minEdgeEnd);
            isolateVertex(edges[minEdgeEnd], added[i]);
            //cout << "delete " << minEdgeEnd << " in "<< added[i] << endl;
            //cout << "delete " << added[i] << " in "<< minEdgeEnd << endl;
        }
        numberOfAdded++;
    }
    return newMatrix;
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

        List* *edges = new List*[n];
        //int *newMatrix = new int[n * n];

        for (int i = 0; i < n; i++)
            edges[i] = createList();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int x = 0;
                fscanf(file, "%d", &x);
                //cout << i << " " << j << " " << x << endl;
                addValue(edges[i], x, j);
                //newMatrix[i + j * n] = x;
            }
        fclose(file);
        //return 0;
        int *newMatrix = primSpanningTree(edges, n);

        cout << "Spanning tree : \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", newMatrix[i * n + j]);
            printf("\n");
        }
    }
    return 0;
}
