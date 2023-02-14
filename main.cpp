#include <iostream>
#include <ctime>

using namespace std;

void del_block(int**& array, int col, int& row, int pos);


int main()
{
    srand(time(0));
    int row, col;
    cout << "Enter rows: ";
    cin >> row;
    cout << "Enter columns: ";
    cin >> col;

    int** array = new int* [row];
    for (size_t i = 0; i < row; i++)
    {
        array[i] = new int[col];
        for (size_t j = 0; j < col; j++)
        {
            array[i][j] = rand() % 100;
            cout << array[i][j] << "\t";
        }
        cout << "\n\n\n" << endl;
    }
    int pos;
    cout << "Enter pos ->";
    cin >> pos;
    del_block(array, col, row, pos);
    cout << "\nRemastered\n\n\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << "\n\n\n" << endl;
    }
    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}


void del_block(int**& array, int col, int& row, int pos)
{
    int** new_arr = new int* [row - 1];
    for (int i = 0; i < pos; i++)
    {
        new_arr[i] = array[i];
    }
    for (int i = pos; i < row; i++)
    {
        new_arr[i - 1] = array[i];
    }
    row--;
    delete[] array[pos];
    delete[] array;
    array = new_arr;
}