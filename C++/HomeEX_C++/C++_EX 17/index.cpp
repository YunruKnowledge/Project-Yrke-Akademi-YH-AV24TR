#include <iostream>

using namespace std;

int _amountOfDigits = 0;

int amountOfDigits(int val);
int calculatePower(int x, int y);

int main(void)
{
    int randomNum = {435};

    cout << "Number has: " << amountOfDigits(randomNum) << " digits" << endl;

    cout << "2 power of 3 is: " << calculatePower(2, 3) << endl;

    return 0;
}

int amountOfDigits(int val)
{
    if (val % 10 != 0)
    {
        _amountOfDigits++;
        amountOfDigits(val /= 10);
    }
    else
    {
        return _amountOfDigits;
    }

    return _amountOfDigits;
}

int calculatePower(int x, int y)
{
    return y > 1 ? calculatePower(x *= x, --y) : x;
}
