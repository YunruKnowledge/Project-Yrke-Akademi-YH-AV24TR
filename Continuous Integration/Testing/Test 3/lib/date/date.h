#ifndef DATE_HPP
#define DATE_HPP

#include <chrono>
#include "IDate.h"

class date : public IDate
{
private:
    int year;
    int month;
    int day;

public:
    date()
    {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t timeTemp = std::chrono::system_clock::to_time_t(now);
        const std::tm *local_tm = std::localtime(&timeTemp);

        year = local_tm->tm_year + 1900;
        month = local_tm->tm_mon + 1;
        day = local_tm->tm_mday;
    }

    int getYear(void) override { return year; };

    int getMonth(void) override { return month; };

    int getDay(void) override { return day; };
};

#endif // !DATE_HPP