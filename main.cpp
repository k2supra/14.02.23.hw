#include <iostream>

using namespace std;

int** addColumn(int**& a, size_t m, size_t n, int value)
{
    int** tmp = new int* [n + value] {0};

    for (int i = m - 1; i >= 0; i--)
    {
        tmp[i + value] = a[i];
    }
    for (int i = 0; i < value; i++)
    {
        tmp[i] = new int[m];
    }
    return tmp;
}


int main()
{
    int i, j;
    int colon, line;
    cout << "Enter colon < line ->";
    cin >> colon;
    cout << "\nEnter line ->";
    cin >> line;
    int** array = new int* [line] {0};
    for (i = 0; i < line; i++)
    {
        array[i] = new int[colon] {0};
    }
    for (i = 0; i < colon; i++)
    {
        for (j = 0; j < line; j++)
        {
            array[i][j] = 1;

            cout << array[i][j] << '\t';
        }
        cout << '\n';
    }
    int add;
    cout << "Input add: ";
    cin >> add;
    array = addColumn(array, colon, line, add);
    colon += add;
    for (i = 0; i < colon; i++)
    {
        for (j = 0; j < line; j++)
        {
            array[i][j] = 1;

            cout << array[i][j] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';

    for (i = 0; i < colon; i++)
        delete[]array[i];
    delete[]array;
}