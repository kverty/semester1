#pragma once

///interface to print something somewhere
class Output
{
public:
    virtual ~Output() {}
    virtual void out() = 0;

//protected:
    /// returns array of n squared elements, in the spiral order
    int *squareToLinear(int **matrix, int n);
};
