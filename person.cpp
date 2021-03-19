#include "person.h"
#include "date.h"
#include "location.h"
#include <iostream>
#include <string>
using namespace std;

void person::add_name(string first, string last) {first_name = first; last_name = last;}

void person::add_gender(string _gender) {gender = _gender;}

void person::add_age(int _age) {age = _age;}

void person::add_date(date birth)
    {
     birth_date.add_date(birth.get_day(), birth.get_month(), birth.get_year());
    }

void person::add_residence(location _residence)
    {
     residence.add_country(_residence.get_country());
     residence.add_city(_residence.get_city());
     residence.add_address(_residence.get_street(), _residence.get_number());
    }

string person::get_first_name() { return first_name; }

string person::get_last_name() { return last_name; }

int person::get_age() { return age; }

date person::get_birth() { return birth_date; }

location person::get_residence() { return residence; }

ostream& operator<< (ostream &cout, const person &p)
{
    cout << "Name: " << p.last_name << " " << p.first_name << "\n";
    cout << "Gender: " << p.gender << "\n";
    cout << "Age: " << p.age << "\n";
    cout << p.birth_date << "\n";
    cout << p.residence;
    return cout;
}

istream& operator>> (istream &cin, person &p)
{
    cin >> p.first_name >> p.last_name >> p.gender >> p.age >> p.birth_date >> p.residence;
    return cin;
}

person &person::operator=(const person &p)
{
    this->last_name = p.last_name;
    this->first_name = p.first_name;
    this->gender = p.gender;
    this->age = p.age;
    this->birth_date = p.birth_date;
    this->residence = p.residence;

    return *this;
}
