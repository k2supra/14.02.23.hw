#include <iostream>
#include <ctime>

using namespace std;

void add_block(int**& array, int col, int& row)
{
    int* new_row = new int[col];
    for (int i = 0; i < col; i++)
    {
        new_row[i] = rand() % 100;
    }

    row++;
    int** newArr = new int* [row];
    newArr[0] = new_row;
    for (int i = 1; i < row; i++)
    {
        newArr[i] = array[i - 1];
    }

    delete[] array;
    array = newArr;
}


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
    add_block(array, col, row);
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