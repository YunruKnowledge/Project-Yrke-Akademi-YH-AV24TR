#include <iostream>
#include <regex>
#include <sstream>
#include <string>

constexpr unsigned int DATE_MIN{1};
constexpr unsigned int YEAR_MAX{9999};
constexpr unsigned int MONTH_MAX{12};
constexpr unsigned int DAY_MAX{31};
constexpr unsigned int TIME_MAX{59};
constexpr unsigned int HOUR_MAX{23};
constexpr unsigned int MONTH_DAY_MAX_MODIFIER[12]{0, 2, 0, 1, 0, 1,
                                                  0, 0, 1, 0, 1, 0};
constexpr unsigned int FEBRUARY{2};
constexpr unsigned int LEAP_DAY{1};

bool isLeapYear(const unsigned int _year);

int main(void) {
  std::string _format{"YYYY-MM-DD HH:mm:ss"};
  std::regex _regex(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})");
  std::string _input;
  bool _valid{false};

  std::cout << "Input a timestamp. (" << _format << ")" << std::endl
            << "Input: ";
  std::getline(std::cin, _input);
  std::cout << _input << std::endl;

  if (!std::cin.fail() && std::regex_match(_input, _regex)) {
    unsigned int _year{0}, _month{0}, _day{0}, _hour{0}, _minute{0}, _second{0};
    char _temp;

    std::istringstream _stringStream(_input);
    _stringStream >> _year >> _temp >> _month >> _temp >> _day;
    _stringStream >> _hour >> _temp >> _minute >> _temp >> _second;
    
    if (_year > YEAR_MAX || _month < DATE_MIN || _month > MONTH_MAX ||
        _day < DATE_MIN || _day > DAY_MAX) {
      std::cout << "*Date(s) exceed max." << std::endl;
    } else if (_hour > HOUR_MAX || _minute > TIME_MAX || _second > TIME_MAX) {
      std::cout << "*Time exceed max." << std::endl;
    } else if (isLeapYear(_year) &&
               (_day > DAY_MAX - MONTH_DAY_MAX_MODIFIER[_month - 1])) {
      std::cout << "*Day exceeded max. (incl. leap day)" << std::endl;
    } else if (!isLeapYear(_year) &&
               _day >
                   DAY_MAX - (MONTH_DAY_MAX_MODIFIER[_month - 1] + LEAP_DAY)) {
      std::cout << "*Day exceeded max." << std::endl;
    } else {
      _valid = true;
    }

    if (_valid)
      std::cout << "Timestamp valid." << std::endl;
    else
      std::cout << "Invalid time." << std::endl;
  } else {
    std::cout << "Invalid Format." << std::endl;
  }

  return 0;
}

bool isLeapYear(const unsigned int _year) {
  bool _isLeap{false};
  // leap year if perfectly divisible by 400
  if (_year % 400 == 0) {
    _isLeap = true;
  }
  // not a leap year if divisible by 100
  // but not divisible by 400
  else if (_year % 100 == 0) {
    ;
  }
  // leap year if not divisible by 100
  // but divisible by 4
  else if (_year % 4 == 0) {
    _isLeap = true;
  }
  // all other years are not leap years
  else {
    ;
  }
  return _isLeap;
}