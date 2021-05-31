#include "clock_time.h"
#include <iostream>
using namespace std;

void clock_time::add_time(int _hour, int _minutes, int _seconds)
{
    hour = _hour;
    minutes = _minutes;
    seconds = _seconds;
}

ostream& operator<< (ostream &os, const clock_time &time)
{
    os << "Ora " << time.hour << ":";
    if(time.minutes < 10)
        os << 0 << time.minutes << ":";
    if(time.seconds < 10)
        os << 0 << time.seconds;
    return os;
}

istream& operator>> (istream &is, clock_time &time)
{
    is >> time.hour >> time.minutes >> time.seconds;
    return is;
}

clock_time &clock_time::operator= (const clock_time &time) = default;

