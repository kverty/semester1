#pragma once
#include "subtree.h"

/// class for subtree with two subtrees and operation between them
class OperationSubtree : public Subtree
{
public:
    OperationSubtree(Subtree *leftSubtree, char operation, Subtree *rightSubtree) : leftSubtree(leftSubtree), operation(operation), rightSubtree(rightSubtree) {}
    ~OperationSubtree();
    int count();
    void print();

private:
    Subtree *leftSubtree;
    Subtree *rightSubtree;
    char operation;
};
