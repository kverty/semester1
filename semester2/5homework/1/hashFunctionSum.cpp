#include "hashFunction.h"
#include "hashFunctionSum.h"

using namespace std;

int SumHashFunction::count(const string &str, int module)
{
    int ans = 0;

    for (int i = 0; i < str.length(); i++)
        ans = (ans + (str[i] - '0' - startIndex)) % module;

    return ans;
}

