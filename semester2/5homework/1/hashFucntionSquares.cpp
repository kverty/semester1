#include "hashFunction.h"
#include "hashFunctionSquares.h"

using namespace std;

int SquareHashFunction::count(const string &str, int module)
{
    int ans = 0;

    for (int i = 0; i < str.length(); i++)
        ans = (ans + (str[i] - '0' - startIndex) * (str[i] - '0' - startIndex)) % module;

    return ans;
}
