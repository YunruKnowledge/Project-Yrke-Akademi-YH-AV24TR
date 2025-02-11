#ifndef TODAY_HPP
#define TODAY_HPP

#include "IDate.hpp"

class today {
    int year;
    int month;
    int day;

public:
    friend std::ostream &operator<<(std::ostream &os, const today &today) {
        os << std::to_string(today.day) + std::string("/") + std::to_string(today.month) + std::string("-") +
                std::to_string(today.year);
        return os;
    }

public:
    today(IDate &_date) : year{_date.getYear()}, month{_date.getMonth()}, day{_date.getDay()} {
    }

    bool isLeapYear(void) {
        bool status{false};
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if ((day > days[month - 1]) && (month == 2)) {
            if ((year % 100 != 0) && (year % 4 == 0) || (year % 400 == 0)) {
                if (day == days[month - 1] + 1) {
                    status = true;
                }
            }
        }

        return status;
    }
};

#endif // !TODAY_HPP
