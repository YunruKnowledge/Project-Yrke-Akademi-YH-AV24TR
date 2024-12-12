/*
1. Read a lowercase letter from terminal and convert it to uppercase and then print the converted letter to the terminal.
2. Generate two random numbers and print them to the terminal.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    //hold the user input.
    string input;

    // take the input from user
    cout << "Input a string:\n";
    //Get the enireline until "Enter is pressed"
    getline(cin, input);

    //convert string to uppercase letters using for each loop..
    //everything in "input" gets to be the "c" after each iteration.
    for (char &c : input){
        c = toupper(c);
    }

    cout  << "The uppercased version:\n" << input << endl;

    /*Random number generator*/

    srand(time(NULL));
    int randomNum = rand() % 100;

    cout << randomNum;

    return 0;
}