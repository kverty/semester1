#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int const size = 100;
    char s[size];
    char s1[size];

    cout << "Enter string: " << endl;
    scanf("%s", s);
    cout << "..and substring, which you want to find : " << endl;
    scanf("%s", s1);

    int length1 = strlen(s1);
    int length = strlen(s);
    int answer = 0;

    for (int i = 0; i <= length - length1; i++)
    {
        bool isEqual = true;
        for (int j = 0; j < length1; j++)
        {
            if(s[i + j] != s1[j])
                isEqual = false;
        }
        if (isEqual)
            answer++;
    }

    if (answer == 0)
    {
        cout << "Not found" << endl;
        return 0;
    }

    cout << "String '" << s << "' contains string '" << s1 << "' as substring " << answer << " times" <<  endl;


    return 0;
}
