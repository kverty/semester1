#include "hashFunction.h"
#include "hashFunctionPolynom.h"

using namespace std;

int PolynomHashFunction::count(const string &str, int module)
{
    int degree = 1;
    int prime = 31;
    int ans = 0;

    for (int i = 0; i < str.length(); i++)
    {
        ans = (ans + (str[i] - '0' - startIndex) * degree) % module;
        degree = (degree * prime) % module;
    }
    return ans;
}
