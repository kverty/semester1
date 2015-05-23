#include "example.h"
#include <iostream>

MyError::MyError()
{
    std::cout << "Exception thrown!\n";
}

Example::Example()
{
    std::cout << "Example created!\n";
}

Example::~Example()
{
    std::cout << "Example destroyed!\n";
}
