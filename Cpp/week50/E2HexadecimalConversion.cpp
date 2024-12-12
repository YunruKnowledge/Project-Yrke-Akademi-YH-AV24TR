/*

#include <iostream>
#include <iomanip>

struct data_t{
    mutable int a;
    static int b;
};

int main(void){ 

    // int number = 0;

    const data_t data{10,20}; //an instance of the data
    data.a = 100;
    data.b = 200;



    usleep(1000000);
    return 0;
}

std::hex;//bunu kullanarak convert yapti.

*/
#include <iostream>
#include <iomanip> // For std::hex and std::setfill
#include <limits>

int main() {
    int number;

    while (true) {
        std::cout << "Enter a number (0-255): ";
        std::cin >> number;

        if (std::cin.fail() /*if non-numeric input, return false*/ || number < 0 || number > 255) {
            std::cin.clear(); // Clear the error flag, to keep taking more input.
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number in the range 0-255.\n";
        } else {
            break;
        }
    }

    std::cout << "The hexadecimal representation is: 0x"
              << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << number
              << std::endl;

    return 0;
}
