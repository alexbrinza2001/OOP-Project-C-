#ifndef TEMA_TRAINER_H
#define TEMA_TRAINER_H
#include "person.h"
#include "gym.h"
#include <string>
#include <vector>
using namespace std;

class trainer : public person{

    int experience;
    int price_per_hour;
    vector < string > days_available;
    vector < string > training_types;
    string gym_name;

public:

    trainer()
    {
        first_name = last_name = gender = "";
        age = 0;
        birth_date.add_date(0, 0, 0);
        residence.add_country("");
        residence.add_city("");
        residence.add_address("", 0);
        experience = 0;
        price_per_hour = 0;
        gym_name = "";
    }

    trainer(int _experience, int _price_per_hour, vector < string > d, vector < string > t, string _gym_name)
    {
        experience = _experience;
        price_per_hour = _price_per_hour;
        int s = d.size();
        days_available.clear();
        for(int i = 0; i < s; ++i)
            days_available.push_back(d[i]);
        s = t.size();
        training_types.clear();
        for(int i = 0; i < s; ++i)
            training_types.push_back(t[i]);
        gym_name = _gym_name;
    }

    void add_experience(int e);

    void add_day(string day);

    void add_type(string type);

    void set_price(int price);

    int get_experience();

    int get_price();

    void clear_days();

    void clear_types();

    vector < string > get_days();

    vector < string > get_types();

    string get_gym();

    bool check_day(string day);

    bool check_type(string type);

    friend ostream& operator<< (ostream &cout, const trainer &t);

    friend istream& operator>> (istream &cin, trainer &t);

    trainer &operator=(const trainer &t);
};

#endif
