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
    int age = 0;
    date birth_date;
    location residence;

public:

    person() = default;

    void add_name(string &first, string &last);

    void add_gender(string &Gender);

    void add_age(int _age);

    void add_date(date birth);

    string get_first_name();

    string get_last_name();

    string get_gender();

    int get_age() const;

    date get_birth();

    location get_residence();

    friend ostream& operator<< (ostream &cout, const person &p);

    friend istream& operator>> (istream &cin, person &p);

    person &operator=(const person &p);
};

#endif
