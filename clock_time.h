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

    void add_time(int _hour, int _minutes, int _seconds);

    friend ostream& operator<< (ostream &cout, const clock_time &time);

    friend istream& operator>> (istream &cin, clock_time &time);

    clock_time &operator=(const clock_time &time);

    friend class gym;
};

#endif
