#include "date.h"
#include <iostream>
using namespace std;

void date::add_date(int _day, int _month, int _year) {day = _day; month = _month; year = _year;}

int date::get_day() {return day;}

int date::get_year() {return year;}

int date::get_month() {return month;}

ostream& operator<< (ostream &cout, const date &d)
{
    cout << "Date: " << d.day << "-" << d.month << "-" << d.year;
    return cout;
}

istream& operator>> (istream &cin, date &d)
{
    cin >> d.day >> d.month >> d.year;
    return cin;
}

date &date::operator=(const date &d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;

    return *this;
}
