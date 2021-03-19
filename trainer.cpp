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

ostream& operator<< (ostream &cout, const trainer &t)
{
    cout << "Name: " << t.first_name << " " << t.last_name <<"\n";
    cout << "Gender: " << t.gender << "\n";
    cout << "Age: " << t.age << "\n";
    cout << "Years of experience: " << t.experience << "\n";
    cout << "Days available: ";
    int s = t.days_available.size();
    for(int i = 0; i < s; ++i) cout << t.days_available[i] << " ";
    cout << "\n";
    cout << "Training types: ";
    s = t.training_types.size();
    for(int i = 0; i < s; ++i) cout << t.training_types[i] << " ";
    cout << "\n";

    return cout;
}

trainer &trainer::operator=(const trainer &t)
{
    this->last_name = t.last_name;
    this->first_name = t.first_name;
    this->gender = t.gender;
    this->age = t.age;
    this->birth_date = t.birth_date;
    this->residence = t.residence;
    this->experience = t.experience;
    int s = t.days_available.size();
    this->days_available.clear();
    for(int i = 0; i < s; ++i) this->days_available.push_back(t.days_available[i]);
    s = t.training_types.size();
    this->training_types.clear();
    for(int i = 0; i < s; ++i) this->training_types.push_back(t.training_types[i]);

    return *this;
}

istream& operator>> (istream &cin, trainer &t)
{
    cin >> t.first_name >> t.last_name >> t.gender >> t.age >> t.birth_date >> t.residence >> t.experience;

    return cin;
}
