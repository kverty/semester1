#include "subtree.h"
#include "subtreeNumber.h"
#include "subtreeOperation.h"
#include "mathtree.h"
#include <iostream>
#include <stdio.h>

using namespace std;

const int nameSize = 20;

int main()
{
    char filename[nameSize] = {'\0'};
    MathTree *tree = new MathTree();
    printf("Please, enter the filename : \n");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
        cout << "There is no such file!\n";
    else
        tree->readFromFile(file);
    fclose(file);

    tree->print();
    cout << "\n\nResult :" << tree->count() << endl;
    delete tree;

    return 0;
}
