#include <iostream>

using namespace std;

int main()
{

    int column = 3;
    int row = 3;

    int mArr[column][row];

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << "Input a number column " << i << " row " << j << ": " << endl;
            cin >> mArr[i][j];
            //  mArr[i][j] = j;
        }
    }
    printf("\v");

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << mArr[i][j] << '\t';
        }
        printf("\n");
    }

    return 0;
}