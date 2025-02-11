#include <gtest/gtest.h>
#include "date.hpp"
#include "today.hpp"

TEST(Test, _test)
{
    date date;
    today today{date};

    std::cout << date.getDay() << "/" << date.getMonth() << "-" << date.getYear() << std::endl;
    std::cout << (today.isLeapYear() ? "Today is a leap year!" : "Today is not a leap year") << std::endl;
}