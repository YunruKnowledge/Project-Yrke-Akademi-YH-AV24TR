#include <bitset>
#include <iostream>

using namespace std;

int main(void)
{
    int userInput;
    do
    {
        cout << "Please enter a number in range [0 - 255]: ";
        cin >> userInput;
        if (cin)
        {
            if (userInput > 0 && userInput <= 255)
            {
                cout << "Your number in binary is: " << bitset<8>(userInput).to_string() << endl;
            }
            else
            {
                cout << "Number not in range!" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        else
        {
            cout << "Input must be a number!" << endl;
            cin.clear();
            cin.ignore();
        }
    } while (1);
}
