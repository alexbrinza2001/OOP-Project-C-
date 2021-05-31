#include "location.h"
#include <iostream>
#include <string>
using namespace std;

void location::add_country(string &Country) {country = Country;}

void location::add_city(string &City) {city = City;}

void location::add_address(string &Street, int &Number) {street = Street; number = Number;}

string location::get_country() {return country;}

string location::get_city() {return city;}

string location::get_street() {return street;}

int location::get_number() const {return number;}

ostream& operator<< (ostream &os, const location &place)
{
    os << "Country: " << place.country << "\n" << "City: " << place.city << "\n" << "Street: " << place.street << "\n" << "Number:" << place.number;
    return os;
}

istream& operator>> (istream &is, location &place)
{
    is >> place.country >> place.city >> place.street >> place.number;
    return is;
}

location &location::operator=(const location &place) = default;

