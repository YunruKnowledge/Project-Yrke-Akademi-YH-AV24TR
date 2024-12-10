#include <iostream>

using namespace std;

void evenNumbers(int val);

int main(void)
{
    int userInput;

    cout << "Enter the number above 0: " << endl;
    cin >> userInput;

    if (cin)
    {
        if (userInput > 0)
        {
            evenNumbers(userInput);
        }
        else
        {
            cout << "Input is not in range!" << endl;
        }
    }
    else
    {
        cout << "Input needs to be a number!" << endl;
    }

    return 0;
}

void evenNumbers(int val)
{
    for (size_t i = 0; i < val; i++)
    {
        if (i % 2 == 0)
        {
            cout << "Number: " << i << " is even!";
        }
        cout << endl;
    }
}