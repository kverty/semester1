#include <iostream>
#include "mathtree.h"

using namespace std;

int main()
{
    Tree *mathtree = readTree();
    printTree(mathtree);
    cout << "\nValue : ";
    cout << countValueOfTree(mathtree);
    deleteTree(mathtree);
    return 0;
}

