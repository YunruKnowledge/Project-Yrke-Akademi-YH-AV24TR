#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ROW 2
#define COLUMN 3

#define MAX_RAND_VAL 99

void fillMatrixWithRandomNumbers(int arr[ROW][COLUMN]);

void printMatrix(int arr[ROW][COLUMN]);

int main()
{
    int arr[ROW][COLUMN];

    srand(time(0));

    fillMatrixWithRandomNumbers(arr);

    cout << "Filled Matrix: " << endl;
    printMatrix(arr);

    return 0;
}

void printMatrix(int arr[ROW][COLUMN])
{
    for (int(*i)[COLUMN] = arr; (i - arr) < ROW; i++)
    {
        for (int *y = *i; (y - *i) < COLUMN; y++)
        {
            std::cout << *y << "\t";
        }
        std::cout << std::endl;
    }
}

void fillMatrixWithRandomNumbers(int arr[ROW][COLUMN])
{
    for (int(*i)[COLUMN] = arr; (i - arr) < ROW; i++)
    {
        for (int *y = *i; (y - *i) < COLUMN; y++)
        {
            *y = std::rand() % (MAX_RAND_VAL + 1);
        }
    }
}