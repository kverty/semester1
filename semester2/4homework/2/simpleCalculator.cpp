#include "simpleCalculator.h"

SimpleCalculator::SimpleCalculator() : firstArgument(0), secondArgument(0), answer(0), operation(0)
{

}

void SimpleCalculator::changeFirstArgument(int value)
{
    firstArgument = value;
    refresh();
}

void SimpleCalculator::changeSecondArgument(int value)
{
    secondArgument = value;
    refresh();
}

void SimpleCalculator::changeOperation(int value)
{
    operation = value;
    refresh();
}

int SimpleCalculator::mAnswer()
{
    return answer;
}

void SimpleCalculator::refresh()
{
    switch(operation)
    {
        case 0:
            answer = firstArgument + secondArgument;
            break;
        case 1:
            answer = firstArgument - secondArgument;
            break;
        case 2:
            answer = firstArgument * secondArgument;
            break;
        case 3:
            if (secondArgument == 0)
                answer = error;
            else
                answer = firstArgument / secondArgument;
            break;
    }
}
