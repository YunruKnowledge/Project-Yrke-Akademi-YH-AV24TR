#include <iostream>
#include <vector>

std::vector<std::pair<int, std::string>> roman_numerals = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

void translate_to_roman(void);
void translate_to_decimal(void);

int main() {
    translate_to_roman();
    translate_to_decimal();

    return 0;
}

void translate_to_roman() {
    int decimal_number{0};
    std::string roman_string;

    std::cout << "Enter a number: ";
    std::cin >> decimal_number;

    for (const auto& roman_pair : roman_numerals) {
        while (decimal_number >= roman_pair.first) {
            roman_string += roman_pair.second;
            decimal_number -= roman_pair.first;
        }
    }

    std::cout << "Roman Number: " << roman_string << std::endl;
}

void translate_to_decimal() {
    std::string roman_string;
    int decimal_number{0};

    std::cout << "Enter a number in roman: ";
    std::cin >> roman_string;

    for (const auto& roman_pair : roman_numerals) {
        while (roman_string.find(roman_pair.second) == 0) {
            decimal_number += roman_pair.first;
            roman_string.erase(0, roman_pair.second.length());
        }
    }

    std::cout << "Decimal Number: " << decimal_number << std::endl;
}