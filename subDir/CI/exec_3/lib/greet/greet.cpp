
#include <cctype>
#include <iostream>
#include <string>

static bool check_for_space(const std::string &_name) {
  return _name.find(" ") != _name.npos ? true : false;
}

std::string greet(const std::string &_name) {
  std::string temp;

  if (_name.empty()) {
    // if empty string
    temp = "Hello, my friend";
  } else if (check_for_space(_name)) {
    // if string has spaces e.g. multiple names
    temp += "Hello ";

    size_t word_amount{1}, word_index{1};
    char previous_char{' '};

    for (const char &c : _name) {
      if (c == ' ' && previous_char != ' ') {
        word_amount++;
      } else {
        ;
      }
      previous_char = c;
    }

    for (const char &c : _name) {
      if (c == ',') {
        ;
      } else if (c != ' ') {
        temp += c;
      } else if (c == ' ' && previous_char != ' ') {
        if (word_index == word_amount - 1) {
          temp += " and ";
        } else {
          temp += ", ";
        }
        word_index++;
      } else {
        ;
      }
      previous_char = c;
    }
  } else {
    // else string has no spaces, e.g. one name
    temp += "Hello ";
    temp += _name;
  }

  return temp;
}

int main(void) {

  std::string temp{"Balls, Falls"};
  std::cout << greet(temp) << std::endl;

  return 0;
}