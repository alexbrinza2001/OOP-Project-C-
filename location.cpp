#include "location.h"
#include <iostream>
#include <string>
using namespace std;

void location::add_country(string _country) {country = _country;}

void location::add_city(string _city) {city = _city;}

void location::add_address(string _street, int _number) {street = _street; number = _number;}

string location::get_country() {return country;}

string location::get_city() {return city;}

string location::get_street() {return street;}

int location::get_number() {return number;}

ostream& operator<< (ostream &cout, const location &place)
{
    cout << "Country: " << place.country << "\n" << "City: " << place.city << "\n" << "Street: " << place.street << "\n" << "Number:" << place.number;
    return cout;
}

istream& operator>> (istream &cin, location &place)
{
    cin >> place.country >> place.city >> place.street >> place.number;
    return cin;
}

location &location::operator=(const location &place)
{
    this->country = place.country;
    this->city = place.city;
    this->street = place.street;
    this->number = place.number;

    return *this;
}

