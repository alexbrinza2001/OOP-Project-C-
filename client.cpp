#include "client.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void client::set_first_name(string first)
{
    first_name = first;
}

void client::set_last_name(string last)
{
    last_name = last;
}

void client::set_city(string _city)
{
    city = _city;
}

void client::add_day(string const day)
{
    days_available.push_back(day);
}

string client::get_first_name() {return first_name;};

string client::get_last_name() {return last_name;};

string client::get_city() {return city;};

vector < string > client::get_days() {return days_available;}

void client::remove_days()
{
    days_available.clear();
}

ostream& operator<< (ostream &os, const client &c)
{
    os << "Name: " << c.first_name << " " << c.last_name << "\n";
    os << "City: " << c.city << "\n";
    os << "Days available: ";
    int s = c.days_available.size();
    for(int i = 0; i < s; ++i)
        os << c.days_available[i] << " ";
    os << "\n";
    return os;
}

istream& operator>> (istream &is, client &c)
{
    is >> c.first_name >> c.last_name >> c.city;
    return is;
}

client &client::operator=(const client &c)
{
    this->last_name = c.last_name;
    this->first_name = c.first_name;
    this->city = c.city;
    this->days_available.clear();
    int s = c.days_available.size();
    for(int i = 0; i < s; ++i)
        this->days_available.push_back(c.days_available[i]);

    return *this;
}

void client :: add_exercise(exercise e)
{
    exercises.push_back(e);
}

