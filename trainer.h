#ifndef TEMA_TRAINER_H
#define TEMA_TRAINER_H
#include "person.h"
#include <string>
#include <vector>
using namespace std;

class trainer : public person{

    int experience;
    vector < string > days_available;
    vector < string > training_types;

public:

    trainer()
    {
        person();
        experience = 0;
        days_available.clear();
        training_types.clear();
    }

    trainer(int _experience, vector < string > d, vector < string > t)
    {
        experience = _experience;
        int s = d.size();
        days_available.clear();
        for(int i = 0; i < s; ++i)
            days_available.push_back(d[i]);
        s = t.size();
        training_types.clear();
        for(int i = 0; i < s; ++i)
            training_types.push_back(t[i]);
    }

    void add_experience(int e);

    void add_day(string day);

    void add_type(string type);

    int get_experience();

    vector < string > get_days();

    vector < string > get_types();

    void check_day(string day);

    void check_type(string type);

    friend ostream& operator<< (ostream &cout, const trainer &t);

    friend istream& operator>> (istream &cin, trainer &t);

    trainer &operator=(const trainer &t);
};

#endif
