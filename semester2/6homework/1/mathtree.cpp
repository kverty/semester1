#include "mathtree.h"
#include "subtree.h"
#include "subtreeNumber.h"
#include "subtreeOperation.h"
#include "digits.h"
#include <iostream>

using namespace std;

void readSubTree(Subtree* &subtree, FILE *file)
{
    char symbol;
    fscanf(file, "%c", &symbol);

    if (isDigit(symbol))
    {
        subtree = new NumberSubtree(readNumber(file, (symbol - '0')));
        return;
    }

    if (symbol == '-')
    {
        char symbol2;
        fscanf(file, "%c", &symbol2);
        if (isDigit(symbol2))
        {
            subtree = new NumberSubtree(-readNumber(file, (symbol2 - '0')));
            return;
        }
    }

    if (isOperation(symbol))
    {
        Subtree *leftTree = nullptr;
        readSubTree(leftTree, file);
        Subtree *rightTree = nullptr;
        readSubTree(rightTree, file);

        subtree = new OperationSubtree(leftTree, symbol, rightTree);
    }
    else if (symbol != '\n')
    {
       readSubTree(subtree, file);
    }
}

void MathTree::readFromFile(FILE *file)
{
    readSubTree(tree, file);
}
