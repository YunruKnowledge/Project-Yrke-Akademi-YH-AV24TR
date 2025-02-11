#ifndef TODAY_HPP
#define TODAY_HPP

#include "date.hpp"

class today
{
    date date_t;

    int year;
    int month;
    int day;

public:
    today(date &_date) : date_t{_date}, year{date_t.getYear()}, month{date_t.getMonth()}, day{date_t.getDay()} {}

    bool isLeapYear(void)
    {
        bool status{false};
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if ((day > days[month - 1]) && (month == 2))
        {
            if ((year % 400 == 0) && (year % 4 == 0) && (year % 100 != 0))
            {
                if (day == days[month - 1] + 1)
                {
                    status = true;
                }
            }
        }

        return status;
    }
};

#endif // !TODAY_HPP