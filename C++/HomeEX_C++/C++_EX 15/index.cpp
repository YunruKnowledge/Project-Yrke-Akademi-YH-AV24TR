#include <iostream>

using namespace std;

bool checkPrime(int val);

int main(void)
{
    int userInput;

    cout << "Input a positive number to check if prime: ";
    cin >> userInput;

    if (cin)
    {
        if (checkPrime(userInput))
        {
            cout << "Your number: " << userInput << " is a prime number!" << endl;
        }
        else
        {
            cout << "Your number: " << userInput << " is not a prime number!" << endl;
        }
    }
    else
    {
        cout << "Wrong input! Input must be a number" << endl;
    }
}

bool checkPrime(int val)
{
    bool isPrime;
    int check = 0;

    if (val <= 1)
        isPrime = false;
    else
    {
        for (int i = 1; i <= val; i++)
        {
            if (val % i == 0)
                check++;
        }

        if (check > 2)
            isPrime = false;
        else
            isPrime = true;
    }

    return isPrime;
}