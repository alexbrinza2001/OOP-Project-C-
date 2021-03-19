#ifndef TEMA_CLOCK_TIME_H
#define TEMA_CLOCK_TIME_H
#include <iostream>
using namespace std;

class clock_time {
    int hour;
    int minutes;
    int seconds;

public:

    clock_time() {
        hour = minutes = seconds = 0;
    }

    clock_time(int _hour, int _minutes, int _seconds) {
        hour = _hour;
        minutes = _minutes;
        seconds = _seconds;
    }

    void add_time(int _hour, int _minutes, int _seconds);

    int get_hour();

    int get_minutes();

    int get_seconds();

    friend ostream& operator<< (ostream &cout, const clock_time &time);

    friend istream& operator>> (istream &cin, clock_time &time);

    clock_time &operator=(const clock_time &time);

    friend class gym;
};

#endif
