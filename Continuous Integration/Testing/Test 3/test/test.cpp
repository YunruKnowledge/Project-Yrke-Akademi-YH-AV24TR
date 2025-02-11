#include <gtest/gtest.h>
#include "today.hpp"
#include "IDate.hpp"

class date : public IDate {
private:
    int year;
    int month;
    int day;

public:
    bool setDate(const std::string &date) {
        int res = std::sscanf(date.c_str(), "%d/%d-%d", &day, &month, &year);
        return res == 3;
    }

    int getYear(void) override { return year; };

    int getMonth(void) override { return month; };

    int getDay(void) override { return day; };
};

TEST(Test, _test) {
    date date;
    date.setDate("29/2-2024");
    today today{date};

    std::cout << (today.isLeapYear() ? "Today is a leap year!" : "Today is not a leap year") << std::endl;
    std::cout << today << std::endl;
}
