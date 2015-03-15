#pragma once

/// to simplify work with operatons
enum Operation
{
    pluss = 0,
    minus,
    mult,
    divide
};

const int error = 10000;

/// calculator with 2 argumets and 1 operation
class SimpleCalculator
{
public:
    SimpleCalculator();
    /// to get answer
    int mAnswer();
    void changeFirstArgument(int value);
    void changeSecondArgument(int value);
    void changeOperation(int value);

private:
    /// both arguments are between -99 and 99
    int firstArgument;
    int secondArgument;
    int operation;
    /// so the answer is smaller 10000; 10000 means error
    int answer;
    /// recount the expression
    void refresh();
};
