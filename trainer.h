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

    int get_experience();
    vector < string > get_days();
    vector < string > get_types();
};

#endif
