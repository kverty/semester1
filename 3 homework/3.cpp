#include <iostream>

using namespace std;


void printRound(int array[100][100], int numberOfRound, int n)
{
    int startX = n / 2 - 1 + numberOfRound;
    int startY = n / 2 - numberOfRound;
    int dx = -1;
    int dy = 0;
    //cout << "      point (" << startX << " " << startY << ") = " << array[startX][startY] << endl;
    //cout << "vector (" << dx << " " << dy << ")" << endl;
    cout << array[startX][startY] << " ";
    int currentX = startX + dx;
    int currentY = startY + dy;
    while (!((currentX == startX) && (currentY == startY)))
    {
        if (((currentX == n / 2 + numberOfRound) && (currentY == n / 2 + numberOfRound)) ||
            ((currentX == n / 2 - numberOfRound) && (currentY == n / 2 + numberOfRound)) ||
            ((currentX == n / 2 + numberOfRound) && (currentY == n / 2 - numberOfRound)) ||
            ((currentX == n / 2 - numberOfRound) && (currentY == n / 2 - numberOfRound)))
        {
            dx = -dx;
            swap(dx, dy);
        }
        //cout << "      point (" << currentX << " " << currentY << ") = " << array[currentX][currentY] << endl;
        //cout << "vector (" << dx << " " << dy << ")" << endl;
        cout << array[currentX][currentY] << " ";
        currentX += dx;
        currentY += dy;
    }
}

void printSquare(int array[100][100], int n)
{
    cout << array[n / 2][n / 2] << " ";
    for (int i = 1; i <= n / 2; i++)
    {
        //cout << "printRound(" << i << ")" << endl;
        printRound(array, i, n);
    }
}

int main()
{
    cout << "Enter N - size of your array in each of two demensions : " << endl;

    int n = 0;
    cin >> n;
    int array[100][100];

    cout << "I think it is too hard and boring to write 25 and more elements, so I write it myself" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = i*n + j;
            if (array[i][j] < 10)
                cout << " ";
            cout << array[i][j] << "  ";
        }
        cout << endl << endl;
    }

    cout << "Answer : " << endl;
    printSquare(array, n);

    return 0;
}
