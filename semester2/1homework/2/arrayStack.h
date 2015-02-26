#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();

    void push(double value);
    int length();
    double pop();
    double top();
    void print();

private:
    double *array;
    int size;
    int lenght;
};
