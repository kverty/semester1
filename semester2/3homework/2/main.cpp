#include <iostream>
#include "output.h"
#include "outToConsole.h"
#include "outToFile.h"
#include "outputTest.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

const int maxSizeOfName = 100;

enum Command
{
    toFile = 1,
    toConsole = 2
};

int main()
{
    OutputTest test;
    QTest::qExec(&test);
}

