#include <iostream>

using namespace std;

int main(void)
{
    int x;

    cout << "Enter a value between [0 - 255]" << ::endl;
    cin >> x;

    if (cin)
    {
        if (x < 0 || x > 255)
        {
            cout << "Number is not in range!" << ::endl;
        }
        else
        {
            cout << "Your number: " << x << " is in hexadecimal: " << hex << x << ::endl;
        }
    }
    else
    {
        cout << "Input needs to be a number!" << ::endl;
    }

    return 0;
}