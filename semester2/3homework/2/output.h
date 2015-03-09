#pragma once

///interface to print something somewhere
class Output
{
public:
    virtual ~Output() {}
    virtual void out() = 0;
};
