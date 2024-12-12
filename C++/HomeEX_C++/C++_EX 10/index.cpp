#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ROW 2
#define COLUMN 3

void fillMatrixWithRandomNumbers(int **arr, int rows, int column);
void printMatrix(int **arr, int rows, int column);

int main()
{
    int **arr = new int *[ROW];
    for (int i = 0; i < ROW; ++i)
    {
        arr[i] = new int[COLUMN];
    }

    fillMatrixWithRandomNumbers(arr, ROW, COLUMN);

    cout << "Filled Matrix: " << endl;
    printMatrix(arr, ROW, COLUMN);

    for (int i = 0; i < ROW; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

void fillMatrixWithRandomNumbers(int **arr, int rows, int column)
{
    srand(time(0));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            *(*(arr + i) + j) = rand() % 100; 
        }
    }
}

void printMatrix(int **arr, int rows, int column)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << *(*(arr + i) + j) << "\t"; 
        }
        cout << endl;
    }
}