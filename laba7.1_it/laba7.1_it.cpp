#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int** a, int n, int m, int low, int high) // заповнення матриці випадковими числами
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = low + rand() % (high - low + 1); // -21 + rand() % 46
}

void Print(int** a, int n, int m) // виведення матриці
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(5) << a[i][j];

        cout << endl;
    }
    cout << endl;
}

void Change(int** a, int j1, int j2, int n) // поміняти два стовпці місцями
{
    for (int i = 0; i < n; i++)
    {
        int tmp = a[i][j1];
        a[i][j1] = a[i][j2];
        a[i][j2] = tmp;
    }
}

void Sort(int** a, int n, int m) // сортування масиву
{
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - i - 1; j++) // m - i - 1 . щоб не перевіряти стовпці, які вже стоять на своїх місцях після попередніх проходів
            if (a[0][j] < a[0][j + 1] || // якщо ліве число менше правого - міняємо стовпці місцями бо потрібно за спаданням
                (a[0][j] == a[0][j + 1] && a[1][j] < a[1][j + 1]) ||  // якщо числа першого рядка однакові, порівнюємо другий рядок
                (a[0][j] == a[0][j + 1] && a[1][j] == a[1][j + 1] && a[2][j] > a[2][j + 1])) // Якщо перший і другий рядки однакові, порівнюємо третій , тут за зростанням
            {
                Change(a, j, j + 1, n);
            }
}

void Calc(int** a, int n, int m, int& s, int& k) // знайти суму та кількість потрібних чисел і замінити їх нулями
{
    s = 0;
    k = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] >= 0 && a[i][j] % 3 == 0)
            {
                s += a[i][j];
                k++;
                a[i][j] = 0;
            }
}

int main()
{
    srand((unsigned)time(NULL));

    int n = 9, m = 6;
    int low = -21, high = 24;

    int** a = new int* [n];

    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    Create(a, n, m, low, high);

    cout << "Original matrix:" << endl;
    Print(a, n, m);

    Sort(a, n, m);

    cout << "Sorted matrix:" << endl;
    Print(a, n, m);

    int s, k;
    Calc(a, n, m, s, k);

    cout << "S = " << s << endl;
    cout << "k = " << k << endl;

    cout << "Modified matrix:" << endl;
    Print(a, n, m);

    for (int i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}
