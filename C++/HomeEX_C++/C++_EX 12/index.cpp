#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    tm time;

    cout << "Enter Time in format of [HH:MM:SS]:" << endl;

    if (cin >> get_time(&time, "%H:%M:%S"))
    {
        cout << "Your time input of: " << put_time(&time, "%H:%M:%S") << " is a correct format" << endl;
    }
    else
    {
        cout << "Wrong Format! Try Again!" << endl;
    }

    return 0;
}