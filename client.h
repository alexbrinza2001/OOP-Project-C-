#ifndef TEMA_CLIENT_H
#define TEMA_CLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include "exercise.h"
using namespace std;

class client {

    string first_name;
    string last_name;
    vector < string > days_available;
    string city;
    vector < exercise > exercises;

public:

    client(){
        first_name = last_name = city = "";
    }

    client(string &first, string &last, vector < string > days, string &_city)
    {
        first_name = first;
        last_name = last;
        days_available.clear();
        int s = days.size();
        for(int i = 0; i < s; ++i)
            days_available.push_back(days[i]);
        city = _city;
    }

    ~client(){
        first_name = last_name = city = "";
        days_available.clear();
    }

    void remove_days();

    void set_first_name(string &first);

    void set_last_name(string &last);

    void set_city(string &city);

    void add_day(string const &day);

    string get_first_name();

    string get_last_name();

    string get_city();

    vector < string > get_days();

    friend ostream& operator<< (ostream &cout, const client &c);

    friend istream& operator>> (istream &cin, client &c);

    client &operator=(const client &c);

    void add_exercise(exercise const &e);

};


#endif
