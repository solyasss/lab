#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : day(1), month(3), year(2005) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::get_day() const
{
    return day;
}

int Date::get_month() const
{
    return month;
}

int Date::get_year() const
{
    return year;
}

void Date::set_day(int d)
{
    if (d >= 1 && d <= 31)
    {
        day = d;
    }
    else
    {
        cout << "Incorrect day" << endl;
    }
}

void Date::set_month(int m)
{
    if (m >= 1 && m <= 12)
    {
        month = m;
    }
    else
    {
        cout << "Incorrect month" << endl;
    }
}

void Date::set_year(int y)
{
    if (y >= 2000 && y <= 2100)
    {
        year = y;
    }
    else
    {
        cout << "Incorrect year" << endl;
    }
}

Date &Date::operator++()
{
    day++;
    if (day > 31)
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    Date temp(*this);
    operator++();
    return temp;
}

Date &Date::operator--()
{
    day--;
    if (day < 1)
    {
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
        day = days_in_month(month, year);
    }
    return *this;
}

Date Date::operator--(int)
{
    Date temp(*this);
    operator--();
    return temp;
}

int days_in_month(int month, int year)
{
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

Date Date::operator+(int days) const
{
    Date result(*this);
    for (int i = 0; i < days; ++i)
    {
        ++result;
    }
    return result;
}

Date Date::operator-(int days) const
{
    Date result(*this);
    for (int i = 0; i < days; ++i)
    {
        --result;
    }
    return result;
}

Date &Date::operator+=(int days)
{
    for (int i = 0; i < days; ++i)
    {
        ++(*this);
    }
    return *this;
}

Date &Date::operator-=(int days)
{
    for (int i = 0; i < days; ++i)
    {
        --(*this);
    }
    return *this;
}

bool Date::operator<(const Date &other) const
{
    if (year < other.year)
    {
        return true;
    }
    else if (year > other.year)
    {
        return false;
    }
    else if (month < other.month)
    {
        return true;
    }
    else if (month > other.month)
    {
        return false;
    }
    else
    {
        return day < other.day;
    }
}

bool Date::operator>(const Date &other) const
{
    return other < *this;
}

bool Date::operator<=(const Date &other) const
{
    return !(*this > other);
}

bool Date::operator>=(const Date &other) const
{
    return !(*this < other);
}

bool Date::operator==(const Date &other) const
{
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date &other) const
{
    return !(*this == other);
}
