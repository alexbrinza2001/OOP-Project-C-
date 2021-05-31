#include "exercise.h"
#include <iostream>
#include <string>
using namespace std;

ostream& operator<< (ostream &cout, const exercise &e)
{
    cout << "Exercise name: " << e.name << "\n";
    cout << "Number of reps: " << e.reps << "\n";
    cout << "Number of series: " << e.series;
    return cout;
}

istream& operator>> (istream &cin, exercise &e)
{
    cin >> e.name >> e.reps >> e.series;
    return cin;
}

exercise &exercise::operator=(const exercise &e)
{
    this->name = e.name;
    this->reps = e.reps;
    this->series = e.series;

    return *this;
}
