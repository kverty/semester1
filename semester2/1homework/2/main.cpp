#include <iostream>
#include "stack.h"
#include "simpleStack.h"
#include "arrayStack.h"

using namespace std;

int main()
{
    Stack *stack = new SimpleStack();
    stack->push(2);
    stack->push(3);
    stack->push(5);
    stack->push(2);
    stack->push(3);
    stack->push(5);
    stack->print();
    cout << endl;
    cout << stack->top() << endl;
    stack->pop();
    stack->print();
    cout << endl;

    Stack *arrStack = new ArrayStack();
    arrStack->push(2);
    arrStack->push(3);
    arrStack->push(5);
    arrStack->push(2);
    arrStack->push(3);
    arrStack->push(5);
    arrStack->print();
    cout << endl;
    cout << arrStack->top() << endl;
    arrStack->pop();
    arrStack->print();
    cout << endl;
    return 0;
}
