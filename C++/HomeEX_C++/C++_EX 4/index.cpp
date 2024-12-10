#include <cstdlib>
#include <iostream>

using namespace std;

string convertCase(string _string);
int getRandomNumber(void);

int main(void)
{
    string userInputString;

    cout << "Enter a string: ";
    cin >> userInputString;

    cout << "Your string: " << userInputString << " is now in all lowercase letters: " << convertCase(userInputString) << endl;
    cout << "Random number: " << getRandomNumber() << endl;

    return 0;
}

string convertCase(string _string)
{
    string newString;
    for (size_t i = 0; i < _string.size(); i++)
    {
        newString += tolower(_string[i]);
    }

    return newString;
}

int getRandomNumber(void)
{
    srand((unsigned)time(0));
    return (rand() % 6) + 1;
}