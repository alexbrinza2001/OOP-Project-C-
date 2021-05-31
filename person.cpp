#include "person.h"
#include <iostream>
#include <string>
using namespace std;

void person::add_name(string &first, string &last) {first_name = first; last_name = last;}

void person::add_gender(string &Gender) {gender = Gender;}

void person::add_age(int _age) {age = _age;}

void person::add_date(date birth)
    {
     birth_date.add_date(birth.get_day(), birth.get_month(), birth.get_year());
    }

string person::get_first_name() { return first_name; }

string person::get_last_name() { return last_name; }

string person::get_gender() {return gender;}

int person::get_age() const { return age; }

date person::get_birth() { return birth_date; }

location person::get_residence() { return residence; }

ostream& operator<< (ostream &os, const person &p)
{
    os << "Name: " << p.last_name << " " << p.first_name << "\n";
    os << "Gender: " << p.gender << "\n";
    os << "Age: " << p.age << "\n";
    os << p.birth_date << "\n";
    os << p.residence;
    return os;
}

istream& operator>> (istream &is, person &p)
{
    is >> p.first_name >> p.last_name >> p.gender >> p.age >> p.birth_date >> p.residence;
    return is;
}

person &person::operator=(const person &p) = default;
