#ifndef IDATE_HPP
#define IDATE_HPP

class IDate
{
public:
    virtual int getYear(void) = 0;
    virtual int getMonth(void) = 0;
    virtual int getDay(void) = 0;

    virtual ~IDate() = default;
};

#endif // !IDATE_HPP