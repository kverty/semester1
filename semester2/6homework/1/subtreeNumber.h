#pragma once
#include "subtree.h"
#include <iostream>

/// class for subtree that contains only one number
class NumberSubtree : public Subtree
{
public:
    NumberSubtree(int x) : number(x) {}
    int count()
    {
        return number;
    }

    void print()
    {
        std::cout << number << " ";
    }

private:
    int number;
};
