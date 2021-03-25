#ifndef TEMA_PERSON_H
#define TEMA_PERSON_H
#include "date.h"
#include "location.h"
#include <iostream>
#include <string>
using namespace std;

class person {

protected:

    string first_name;
    string last_name;
    string gender;
    int age;
    date birth_date;
    location residence;

public:

    person() {
        first_name = last_name = gender = "";
        age = 0;
        birth_date.add_date(0, 0, 0);
        residence.add_country("");
        residence.add_city("");
        residence.add_address("", 0);
    }

    person(string _first, string _last, string _gender, int _age, date _birth, location _residence) {
        first_name = _first;
        last_name = _last;
        gender = _gender;
        age = _age;
        birth_date = _birth;
        residence = _residence;
    }

    void add_name(string first, string last);

    void add_gender(string _gender);

    void add_age(int _age);

    void add_date(date birth);

    void add_residence(location _residence);

    string get_first_name();

    string get_last_name();

    string get_gender();

    int get_age();

    date get_birth();

    location get_residence();

    friend ostream& operator<< (ostream &cout, const person &p);

    friend istream& operator>> (istream &cin, person &p);

    person &operator=(const person &p);
};

#endif
