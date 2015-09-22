#include <iostream>
#include "localnetwork.h"

const int maxSizeOfName = 100;

using namespace std;

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

    LocalNetwork *network = new LocalNetwork(file);

    return 0;
}
