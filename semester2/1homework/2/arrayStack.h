#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();

    void push(int value);
    int length();
    int pop();
    int top();
    void print();

private:
    int *array;
    int size;
    int lenght;
};
