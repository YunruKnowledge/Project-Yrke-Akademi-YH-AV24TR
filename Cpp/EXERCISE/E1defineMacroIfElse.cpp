#include <iostream>

#define NUMBER 8

int main() {
    #if (NUMBER != 8) && (NUMBER != 16)
    #error "Macro NUMBER must be either 8 or 16."
    #endif

    std::cout << "Macro NUMBER is defined and has the value: " << NUMBER << std::endl;
    return 0;
}
