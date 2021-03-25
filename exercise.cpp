#include "exercise.h"
#include <iostream>
#include <string>
using namespace std;

void exercise::set_exercise(string _name, string _area, int _reps, int _series)
{
    name = _name;
    trained_area = _area;
    reps = _reps;
    series = _series;
}

string exercise::get_name() {return name;}

string exercise::get_area() {return trained_area;}

int exercise::get_reps() {return reps;}

int exercise::get_series() {return series;}

ostream& operator<< (ostream &cout, const exercise &e)
{
    cout << "Exercise name: " << e.name << "\n";
    cout << "Trained area: " << e.trained_area << "\n";
    cout << "Number of reps: " << e.reps << "\n";
    cout << "Number of series: " << e.series;
    return cout;
}

istream& operator>> (istream &cin, exercise &e)
{
    cin >> e.name >> e.trained_area >> e.reps >> e.series;
    return cin;
}

exercise &exercise::operator=(const exercise &e)
{
    this->name = e.name;
    this->trained_area = e.trained_area;
    this->reps = e.reps;
    this->series = e.series;

    return *this;
}
