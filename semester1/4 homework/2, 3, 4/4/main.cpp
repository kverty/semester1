#include <iostream>
//#include "expressions.h"
#include "stack.h"

using namespace std;

int main()
{
    //cout << "Enter your math expressionin normal form:" << endl;
    //char polishExpression[100] = normalToPolish(normalExpression);
    //cout << polishToAnswer(polishExpression) << endl;
    cout << "Result : " << polishToAnswer(normalToPolish()) << endl;
    return 0;
}

