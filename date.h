#ifndef TEMA_DATE_H
#define TEMA_DATE_H
#include <iostream>
using namespace std;

class date {
    int day;
    int month;
    int year;

public:

    date() {
        day = month = year = 0;
    }

    void add_date(int _day, int _month, int _year);

    int get_day() const;

    int get_month() const;

    int get_year() const;

    friend ostream& operator<< (ostream &cout, const date &d);

    friend istream& operator>> (istream &cin, date &d);

    date &operator=(const date &d);

    friend class person;
};

#endif
