// lab 7.3 rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int K, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, K, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, K, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}
void PrintRows(int** a, const int N, const int K, int rowNo)
{
    PrintRow(a, rowNo, K, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, K, rowNo + 1);
    else
        cout << endl;
}

void firstZero(int** a, int rowCount, int colCount, int i, int j, int colNumber)
{
    if (i < colCount)
    {
        if (colNumber == -1)
        {
            for (int j = 0; j < rowCount; j++)
            {
                if (!(a[j][i] == 0))
                    colNumber = i;
            }
        }
        firstZero(a, rowCount, colCount, ++i, j, colNumber);
    }
    else
        cout << "Перший не 0 в колонке: " << colNumber + 1 << endl;
}

void Change(int** a, int colCount, int row1, int row2, int i)
{
    if (i < colCount)
    {
        int temp = a[row1][i];
        a[row1][i] = a[row2][i];
        a[row2][i] = temp;
        Change(a, colCount, row1, row2, ++i);
    }
}

int rowSum(int** a, int row, int colCount, int sum, int i)
{
    if (i < colCount)
    {
        if (a[row][i] < 0 && a[row][i] % 2 == 0)
        {
            sum += a[row][i];
        }
        rowSum(a, row, colCount, sum, ++i);
    }
    else
        return sum;
}

void chagneRows(int** a, int rowCount, int colCount, int j, int i)
{
    if (j < rowCount - 1)
    {
        if (i < rowCount - j - 1)
        {
            if (rowSum(a, i, colCount, 0, 0) > rowSum(a, i + 1, colCount, 0, 0))
            {
                Change(a, colCount, i, i + 1, 0);
            }
            chagneRows(a, rowCount, colCount, j, ++i);
        }
        chagneRows(a, rowCount, colCount, ++j, 0);
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int Low = -10;
    int High = 10;
    int rowCount;
    int colCount;
    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);
    PrintRows(a, colCount, rowCount, 0);

    firstZero(a, rowCount, colCount, 0, 0, -1);

    chagneRows(a, rowCount, colCount, 0, 0);
    PrintRows(a, colCount, rowCount, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
