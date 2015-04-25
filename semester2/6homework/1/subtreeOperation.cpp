#include "subtree.h"
#include "subtreeOperation.h"
#include <iostream>

OperationSubtree::~OperationSubtree()
{
    delete leftSubtree;
    delete rightSubtree;
}

int OperationSubtree::count()
{
    int firstNumber = leftSubtree->count();
    int secondNumber = rightSubtree->count();

    switch(operation)
    {
    case '+' :
        return firstNumber + secondNumber;
        break;
    case '-':
        return firstNumber - secondNumber;
        break;
    case '*':
        return firstNumber * secondNumber;
        break;
    case '/':
        return firstNumber / secondNumber;
        break;
    };
}

void OperationSubtree::print()
{
    std::cout << "( ";
    std::cout << operation << " ";
    leftSubtree->print();
    rightSubtree->print();
    std::cout << ") ";
}
