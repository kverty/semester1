#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSizeOfName = 100;

void inc(char &c)
{
    c = ((c - '0') + 1) + '0';
}

void dfs(int vertex, bool *matrix, char* &isVisited, int numberOfVertexes, char &nextLetter)
{
    for (int i = 0; i < numberOfVertexes; i++)
    {
        if ((matrix[numberOfVertexes * vertex + i]) && (isVisited[i] == '\n'))
        {
            isVisited[i] = nextLetter;
            inc(nextLetter);
            dfs(i, matrix, isVisited,  numberOfVertexes, nextLetter);
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
        char *isVisited = new char[n];

        for (int i = 0; i < n; i++)
            isVisited[i] = '\n';

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int x = 0;
                fscanf(file, "%d", &x);
                matrix[i * n + j] = (x == 1);
            }
        fclose(file);

        int vertex = 0;
        char newChar = 'b';

        cout << "Enter the number of start: \n";
        cin >> vertex;

        isVisited[vertex - 1] = 'a';
        dfs(vertex - 1, matrix, isVisited, n, newChar);

        cout << endl;
        for (int i = 0; i < n; i++)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << isVisited[i] << " ";
    }
    return 0;
}
