#include <cstdio>
#include <iostream>

using namespace std;

#define ROW 3
#define COLUMN 3

int main(void)
{
    int matrix[ROW][COLUMN];
    int userInput;

    for (size_t i = 0; i < ROW; i++)
    {
        for (size_t j = 0; j < COLUMN; j++)
        {
            cout << "Insert a number for ROW: " << i << " and COLUMN: " << j << " : ";
            cin >> userInput;

            matrix[i][j] = userInput;
        }
    }

    cout << "\nYour matrix is: " << endl;
    for (size_t i = 0; i < ROW; i++)
    {
        for (size_t j = 0; j < COLUMN; j++)
        {
            cout << "\t" << matrix[i][j];
        }
        cout << endl;
    }
}