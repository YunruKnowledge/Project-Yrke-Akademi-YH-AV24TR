// Make a program to read a std::string from a terminal and then convert
// the uppercase letters to lowercase and vice versa and
// in the end print the string to the standard output.
// To change and print the string use only pointers.

#include <cctype>
#include <iostream>


int main(void) {
  std::string _input;
  std::cout << "Input a string to reverse capitalize it." << std::endl
            << "Input: ";
  std::cin >> _input;
  if (!std::cin.fail()) {
    std::string *_sptr{&_input};

    for (size_t i = 0; i < _input.length(); i++) {
      if (char(tolower((*_sptr)[i])) == (*_sptr)[i]) {
        (*_sptr)[i] = char(toupper((*_sptr)[i]));
      } else {
        (*_sptr)[i] = char(tolower((*_sptr)[i]));
      }
    }

    std::cout << "Result: "<< *_sptr << std::endl;
  } else {
    std::cout << "Input invalid. Exiting..." << std::endl;
  }

  return 0;
}