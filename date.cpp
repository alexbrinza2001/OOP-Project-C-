#include "date.h"
#include <iostream>
using namespace std;

void date::add_date(int _day, int _month, int _year) {day = _day; month = _month; year = _year;}

int date::get_day() const {return day;}

int date::get_year() const {return year;}

int date::get_month() const {return month;}

ostream& operator<< (ostream &os, const date &d)
{
    os << "Date: " << d.day << "-" << d.month << "-" << d.year;
    return os;
}

istream& operator>> (istream &is, date &d)
{
    is >> d.day >> d.month >> d.year;
    return is;
}

date &date::operator=(const date &d) = default;
