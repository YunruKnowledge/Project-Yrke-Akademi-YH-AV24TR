
#include <chrono>

class Date {
  uint16_t year;
  uint8_t month, day;

public:
  Date(){};
};

Date::Date() {
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  std::time_t time = std::chrono::system_clock::to_time_t(now);
  std::tm *localTime =
      std::localtime(&time); // year starts at 1900, month starts at 0.

  year = localTime->tm_year + 1900;
  month = localTime->tm_mon + 1;
  day = localTime->tm_mday;
}
