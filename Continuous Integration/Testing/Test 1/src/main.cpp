#include <iostream>
#include "numGenerator.h"
#include "fizzbuzz.h"

constexpr int MIN = 0;
constexpr int MAX = 200;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments!" << std::endl;
        exit(1);
    }

    int number = std::stoi(argv[1]);

    int arr[number];
    NUMGEN::randomNumbers(MIN, MAX, number, arr);


    for (int i = 0; i < number; i++)
    {
        std::cout << fizzbuzz::check(arr[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}