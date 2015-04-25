#pragma once

#include "subtree.h"
#include "subtreeNumber.h"
#include "subtreeOperation.h"

/// class for reading, writing and counting math tree
class MathTree
{
public:
    MathTree() : tree(nullptr)
    {

    }

    ~MathTree()
    {
        delete tree;
    }

    /// prints tree
    void print()
    {
        tree->print();
    }

    /// counts tree
    int count()
    {
        return tree->count();
    }

    /// reads tree
    void readFromFile(FILE *file);

private:
    Subtree *tree;
};
