
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, int rowCount, int colCount, int Low, int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, int rowCount, int colCount)
{
    cout << endl;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

void Change(int** a, int col1, int col2, int rowCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        int tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

void Sort(int** a, int rowCount, int colCount)
{
    for (int i = 0; i < colCount - 1; i++)
        for (int j = 0; j < colCount - i - 1; j++)
        {
            if (a[0][j] < a[0][j + 1] ||
                (a[0][j] == a[0][j + 1] &&
                    a[1][j] < a[1][j + 1]) ||
                (a[0][j] == a[0][j + 1] &&
                    a[1][j] == a[1][j + 1] &&
                    a[2][j] > a[2][j + 1]))
            {
                Change(a, j, j + 1, rowCount);
            }
        }
}

void Calc(int** a, int rowCount, int colCount, int& S, int& k)
{
    S = 0;
    k = 0;

    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] >= 0 && a[i][j] % 3 == 0)
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
}

int main()
{
    srand((unsigned)time(NULL));

    int rowCount = 9;
    int colCount = 6;
    int Low = -21;
    int High = 24;

    int** P = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];

    Create(P, rowCount, colCount, Low, High);

    cout << "Original matrix:";
    Print(P, rowCount, colCount);

    Sort(P, rowCount, colCount);

    cout << "Sorted matrix:";
    Print(P, rowCount, colCount);

    int S, k;

    Calc(P, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    cout << "Modified matrix:";
    Print(P, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] P[i];

    delete[] P;

    return 0;
}
