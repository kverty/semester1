#include "stack.h"
#include "expressions.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();

    void push(Token *token);
    int mLength();
    Token *pop();
    Token *top();
    void print();

private:
    Token* *array;
    int size;
    int length;
};
