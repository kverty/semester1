#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int numberOfDigits = 4;

void rules()
{
    cout << "Welcome to Bulls and Cows" <<endl;
    cout << "You need to guess a four-digit number" << endl;
    cout << "Each turn you need to write " << numberOfDigits << "-digit number, and I will say you how many cows and how many bulls" << endl << endl;
    cout << "x Cows = you guess x digits but they are NOT on the right positions" << endl;
    cout << "x Bulls = you guess x digits and they are on the right positions" << endl << endl;
    return;
}

int countBulls(int a, int b)//(ourNumber & quessedNumber)
{
    int bulls = 0;
    int ourNumber = a;
    int quessedNumber = b;

    for (int i = 0; i < numberOfDigits; i++)
    {
        int ourDigit = ourNumber % 10;
        int quessedDigit = quessedNumber % 10;

        if (ourDigit == quessedDigit)
            bulls ++;

        ourNumber = ourNumber / 10;
        quessedNumber = quessedNumber / 10;
    }
    return bulls;
}

int countCows(int a, int b)//(ourNumber & quessedNumber)
{
    int cows = 0;
    int ourNumber = a;
    int quessedNumber = b;
    int ourDigits[numberOfDigits];
    int quessedDigits[numberOfDigits];

    for (int i = 0; i < numberOfDigits; i++)
    {
        ourDigits[i] = ourNumber % 10;
        quessedDigits[i] = quessedNumber % 10;
        ourNumber = ourNumber / 10;
        quessedNumber = quessedNumber / 10;
    }

    bool isUsed[4]; //I need it; for example - ourNumber = 1214, quessedNumber = 3151 - only 2 cows
    for (int j = 0; j < numberOfDigits; j++)
        isUsed[j] = false;

    for (int t = 0; t < numberOfDigits; t++)
    {
        for (int k = 0; k < numberOfDigits; k++)
        {
            if ((quessedDigits[t] == ourDigits[k]) && (!isUsed[k]))
            {
                isUsed[k] = true;
                cows++;
                break;
            }
        }
    }
    return cows;
}

int main()
{
    rules();

    cout << "Lets start our game!" << endl;

    while (true)
    {
        srand(time(0));
        int myNumber = 1000 + rand() % 9000;
        cout << "Our number is made! " /* << myNumber */<< endl;

        while (true)
        {
            int quess = 0;
            cout << "Your guess : " << endl;
            cin >> quess;

            int numberOfCows = countCows(myNumber, quess);
            int numberOfBulls = countBulls(myNumber, quess);

            if (numberOfBulls == 4)
            {
                cout << "You guess my number!!" << endl;
                break;
            }

            cout << "Cows : " << numberOfCows - numberOfBulls << endl;
            cout << "Bulls : " << numberOfBulls << endl;
        }

        cout << "Do you wanna play one more time?(y/n)" << endl;
        char answer;
        cin >> answer;

        if ((answer == 'n') || (answer == 'N'))
        {
            cout << "Good luck!" << endl;
            break;
        }
    }
    return 0;
}
