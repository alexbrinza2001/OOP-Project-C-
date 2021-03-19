#ifndef TEMA_GYM_H
#define TEMA_GYM_H
#include <iostream>
#include "location.h"
#include "clock_time.h"
using namespace std;

class gym{
    location address;
    clock_time open_time;
    clock_time close_time;

public:

    gym()
    {
        address.add_country("");
        address.add_city("");
        address.add_address("", 0);
        open_time.add_time(0, 0, 0);
        close_time.add_time(0, 0, 0);
    }

    gym(location _address, clock_time open, clock_time close)
    {
        address.add_country(_address.get_country());
        address.add_city(_address.get_city());
        address.add_address(_address.get_street(), _address.get_number());
        open_time.add_time(open.get_hour(), open.get_minutes(), open.get_seconds());
        close_time.add_time(close.get_hour(), close.get_minutes(), close.get_seconds());
    }

    void add_gym(location _address, clock_time open, clock_time close);

    location get_address();

    clock_time get_open();

    clock_time get_close();

    friend ostream& operator<< (ostream &cout, const gym &g);

    friend istream& operator>> (istream &cin, gym &g);

    gym &operator=(const gym &g);

};

#endif
