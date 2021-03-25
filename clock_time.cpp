#include "clock_time.h"
#include <iostream>
using namespace std;

void clock_time::add_time(int _hour, int _minutes, int _seconds)
{
    hour = _hour;
    minutes = _minutes;
    seconds = _seconds;
}

int clock_time::get_hour() {return hour;}

int clock_time::get_minutes() {return minutes;}

int clock_time::get_seconds() {return seconds;}

ostream& operator<< (ostream &cout, const clock_time &time)
{
    cout << "Ora " << time.hour << ":";
    if(time.minutes < 10)
        cout << 0 << time.minutes << ":";
    if(time.seconds < 10)
        cout << 0 << time.seconds;
    return cout;
}

istream& operator>> (istream &cin, clock_time &time)
{
    cin >> time.hour >> time.minutes >> time.seconds;
    return cin;
}

clock_time &clock_time::operator=(const clock_time &time)
{
    this->hour = time.hour;
    this->minutes = time.minutes;
    this->seconds = time.seconds;

    return *this;
}

