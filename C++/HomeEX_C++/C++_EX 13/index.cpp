#include <iostream>

using namespace std;

string reversCase(string text);

int main(void)
{
    string userInput;

    cout << "Input a random string: ";
    cin >> userInput;

    cout << "Your random input is: " << reversCase(userInput) << endl;

    return 0;
}

string reversCase(string text)
{
    string temp;

    for (size_t i = 0; i < text.size(); i++)
    {
        if(text[i] > 'A' && text[i] < 'Z')
            temp += tolower(text[i]);
        else
            temp += toupper(text[i]);
    }
    
    return temp;
}