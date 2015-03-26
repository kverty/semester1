#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();

    void push(int value);
    int mLength();
    int pop();
    int top();
    void print();

private:
    int *array;
    int size;
    int length;
};
