#include <iostream>

using namespace std;

string hexadecimalConverter(int val);

int main(void)
{
    int x;

    ::cout << "Enter a value between [0 - 255]" << ::endl;
    ::cin >> x;

    if (::cin)
    {
        if (x < 0 || x > 255)
        {
            ::cout << "Number is not in range!" << ::endl;
        }
        else
        {
            ::cout << "Your number: " << x << " is in hexadecimal: " << hexadecimalConverter(x) << ::endl;
        }
    }
    else
    {
        ::cout << "Input needs to be a number!" << ::endl;
    }

    return 0;
}

string hexadecimalConverter(int val)
{
    string hexadecimal = " ";

    while (val != 0)
    {
        int rem = 0;
        char ch;

        rem = val % 16;

        if (rem < 10)
            ch = rem + 48;
        else
            ch = rem + 55;

        hexadecimal += ch;
        val /= 16;
    }

    int i = 0;
    int j = hexadecimal.size() - 1;

    while (i <= j)
    {
        swap(hexadecimal[i], hexadecimal[j]);
        i++;
        j--;
    }

    return hexadecimal;
}