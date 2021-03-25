#ifndef TEMA_EXERCISE_H
#define TEMA_EXERCISE_H
#include <iostream>
#include <string>
using namespace std;

class exercise{

    string name;
    string trained_area;
    int reps;
    int series;

public:

    exercise()
    {
        name = trained_area = "";
        reps = series = 0;
    }

    exercise(string _name, string _area, int _reps, int _series)
    {
        name = _name;
        trained_area = _area;
        reps = _reps;
        series = _series;
    }

    void set_exercise(string _name, string _area, int _reps, int _series);

    string get_name();

    string get_area();

    int get_reps();

    int get_series();

    friend ostream& operator<< (ostream &cout, const exercise &e);

    friend istream& operator>> (istream &cin, exercise &e);

    exercise &operator=(const exercise &e);
};


#endif
