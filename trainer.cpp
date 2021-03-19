#include "person.h"
#include "trainer.h"
#include <iostream>
#include <string>
using namespace std;

void trainer::add_experience(int e)
{
    experience = e;
}

void trainer::add_day(string d)
{
    days_available.push_back(d);
}

void trainer::add_type(string t)
{
    training_types.push_back(t);
}

int trainer::get_experience()
{
    return experience;
}

vector < string > trainer::get_days()
{
    return days_available;
}

vector < string > trainer::get_types()
{
    return training_types;
}

void trainer::check_day(string day)
{
    int ok = 0;
    int s = days_available.size();
    for(int i = 0; i < s; ++i)
        if(day == days_available[i])
        {
            ok = 1;
            break;
        }
    if(ok == 1) cout << "Trainer is available.";
    else cout << "Trainer is not available.";
}

void trainer::check_type(string type)
{
    int ok = 0;
    int s = training_types.size();
    for(int i = 0; i < s; ++i)
        if(type == training_types[i])
        {
            ok = 1;
            break;
        }
    if(ok == 1) cout << "Trainer does this training.";
    else cout << "Trainer does not do this training.";
}
