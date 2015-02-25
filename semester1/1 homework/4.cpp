#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int const maxSum = 27;
    int const maxDigit = 9;
    int sum[maxSum];

    for (int t = 0; t <= maxSum; t++)
        sum[t] = 0;
    for (int i = 0; i <= maxDigit; i++)
        for (int j = 0; j <= maxDigit; j++)
            for (int k = 0; k <= maxDigit; k++)
                sum[i + j + k]++;

    int answer = 0;
    for (int l = 0; l <= maxSum; l++)
    {
        answer += sum[l] * sum[l];
    }
    cout << "Number of happy tickets : " << answer << endl;
}
