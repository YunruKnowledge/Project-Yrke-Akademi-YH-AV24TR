#ifndef TODAY_HPP
#define TODAY_HPP

#include "IDate.hpp"

class today {
    int year;
    int month;
    int day;

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

    std::string showDate(void) {
        std::string res;
        res = (std::to_string(day) + std::string("/") + std::to_string(month) + std::string("-") +
               std::to_string(year));

        return res;
    }
};

#endif // !TODAY_HPP
