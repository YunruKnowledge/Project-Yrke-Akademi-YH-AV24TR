
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

static std::string stringify_whole_vector(std::vector<std::string> &_vector,
                                          const bool _isUpperCased) {
  std::string temp{""};

  for (size_t i = 0; i < _vector.size(); i++) {
    if (i == (_vector.size() - 1)) {
      if (_isUpperCased && _vector.size() > 1) {
        temp += " AND ";
      } else if (_vector.size() > 1) {
        temp += " and ";
      }
      temp += _vector.at(i);
    } else {
      temp += _vector.at(i);
      if (_vector.size() > 1 && i < (_vector.size() - 2)) {
        temp += ", ";
      }
    }
  }

  return temp;
}

std::string greet(const std::string &_name) {
  std::string temp;

  if (_name.empty()) {
    // if empty string
    temp = "Hello, my friend.";
  } else {
    // if string has spaces e.g. multiple names
    std::string temp_unknown;
    std::vector<std::string> temp_vect_lower;
    std::vector<std::string> temp_vect_upper;
    size_t temp_pos{0};

    temp = _name;

    while (temp_pos != temp.npos) {
      temp_pos = temp.find(",");
      temp_unknown = temp.substr(0, temp_pos);
      temp = temp.substr(temp_pos + 1);

      bool is_upper{true};
      char previous_char{' '};
      for (char &c : temp_unknown) {
        if (c == ' ' && previous_char == ' ') {
          // may be a potential problem, if INPUT: NAME(space)(space),
          temp_unknown = temp_unknown.substr(1);
        }
        previous_char = c;
      }

      for (char &c : temp_unknown) {
        if (c == static_cast<char>(tolower(c))) {
          is_upper = false;
        }
      }

      if (is_upper) {
        temp_vect_upper.push_back(temp_unknown);
      } else {
        temp_vect_lower.push_back(temp_unknown);
      }
    }

    temp = "";
    if (temp_vect_upper.empty()) {
      temp = "Hello "; // sets
      temp += stringify_whole_vector(temp_vect_lower, false);
      temp += ".";

    } else if (temp_vect_lower.empty()) {
      temp += "HELLO "; // sets
      temp += stringify_whole_vector(temp_vect_upper, true);
      temp += "!";

    } else {
      temp = "Hello "; // sets
      temp += stringify_whole_vector(temp_vect_lower, false);
      temp += ". AND HELLO ";
      temp += stringify_whole_vector(temp_vect_upper, true);
      temp += "!";
    }
  }

  return temp;
}
