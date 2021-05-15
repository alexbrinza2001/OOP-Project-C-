#include "person.h"
#include "trainer.h"
#include "client.h"
#include <iostream>
#include <string>
using namespace std;

void trainer::add_experience(int e)
{
    experience += e;
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

int trainer::get_client_limit()
{
    return client_limit;
}

vector < string > trainer::get_days()
{
    return days_available;
}

vector < string > trainer::get_types()
{
    return training_types;
}

void trainer::set_price(int price)
{
    price_per_hour = price;
}

int trainer::get_price() {return price_per_hour;}

bool trainer::check_day(string day)
{
    int ok = 0;
    int s = days_available.size();
    for(int i = 0; i < s; ++i)
        if(day == days_available[i])
        {
            ok = 1;
            break;
        }

    return ok;
}

void trainer::clear_days()
{
    days_available.clear();
}

void trainer::clear_types()
{
    training_types.clear();
}

bool trainer::check_type(string type)
{
    int ok = 0;
    int s = training_types.size();
    for(int i = 0; i < s; ++i)
        if(type == training_types[i])
        {
            ok = 1;
            break;
        }

    return ok;
}

string trainer::get_gym() {return gym_name;}

ostream& operator<< (ostream &cout, const trainer &t)
{
    cout << "Name: " << t.first_name << " " << t.last_name <<"\n";
    cout << "Gender: " << t.gender << "\n";
    cout << "Age: " << t.age << "\n";
    cout << "Years of experience: " << t.experience << "\n";
    cout << "Price per hour: " << t.price_per_hour << "\n";
    cout << "Days available: ";
    int s = t.days_available.size();
    for(int i = 0; i < s; ++i) cout << t.days_available[i] << " ";
    cout << "\n";
    cout << "Training types: ";
    s = t.training_types.size();
    for(int i = 0; i < s; ++i) cout << t.training_types[i] << " ";
    cout << "\n";
    cout << "Works at: " << t.gym_name;
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
    this->price_per_hour = t.price_per_hour;
    int s = t.days_available.size();
    this->days_available.clear();
    for(int i = 0; i < s; ++i) this->days_available.push_back(t.days_available[i]);
    s = t.training_types.size();
    this->training_types.clear();
    for(int i = 0; i < s; ++i) this->training_types.push_back(t.training_types[i]);
    this->gym_name = t.gym_name;

    return *this;
}

istream& operator>> (istream &cin, trainer &t)
{
    cin >> t.first_name >> t.last_name >> t.gender >> t.age >> t.birth_date >> t.residence >> t.experience >> t.price_per_hour >> t.gym_name;

    return cin;
}

void trainer::add_client(client c)
{
    if(client_list.size() == client_limit)
        throw false;

    client_list.push_back(c);
}

int trainer::get_client_count()
{
    return client_list.size();
}
