#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void add_block(int**& array, int col, int& row, int pos);


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
    add_block(array, col, row, pos);
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


void add_block(int**& array, int col, int& row, int pos)
{
    int* new_row = new int[col];
    for (int i = 0; i < col; i++)
    {
        new_row[i] = rand() % 100;
    }

    row++;
    int** new_arr = new int* [row];
    for (int i = 0; i < pos; i++)
    {
        new_arr[i] = array[i];
    }
    new_arr[pos - 1] = new_row;
    for (int i = pos; i < row; i++)
    {
        new_arr[i] = array[i - 1];
    }
    delete[] array;
    array = new_arr;
}