#include <iostream>

#define NUMBER 8

int main()
{

    if (NUMBER != 8 && NUMBER != 16)
    {
        std::cout << "error, number is not 8 or 16" << std::endl;
        exit(1);
    }

    std::cout << "Macro NUMBER is defined and has the value: " << NUMBER << std::endl;

    return 0;
}
