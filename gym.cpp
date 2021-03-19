#include "gym.h"
#include "location.h"
#include "clock_time.h"
#include <iostream>
using namespace std;

void gym::add_gym(location _address, clock_time open, clock_time close)
{
    address.add_country(_address.get_country());
    address.add_city(_address.get_city());
    address.add_address(_address.get_street(), _address.get_number());
    open_time.add_time(open.get_hour(), open.get_minutes(), open.get_seconds());
    close_time.add_time(close.get_hour(), close.get_minutes(), close.get_seconds());
}

location gym::get_address() {return address;}

clock_time gym::get_open() {return open_time;}

clock_time gym::get_close() {return close_time;}

ostream& operator<< (ostream &cout, const gym &g)
{
    cout << "Address:" << "\n" << g.address << "\n";
    cout << "Program: " << g.open_time << " - " << g.close_time;
    return cout;
}

istream& operator>> (istream &cin, gym &g)
{
    cin >> g.address >> g.open_time >> g.close_time;
    return cin;
}

gym &gym::operator=(const gym &g)
{
    this->address = g.address;
    this->open_time = g.open_time;
    this->close_time = g.close_time;

    return *this;
}
