#include "exercise.h"
#include <iostream>
#include <string>
using namespace std;

ostream& operator<< (ostream &os, const exercise &e)
{
    os << "Exercise name: " << e.name << "\n";
    os << "Number of reps: " << e.reps << "\n";
    os << "Number of series: " << e.series;
    return os;
}

istream& operator>> (istream &is, exercise &e)
{
    is >> e.name >> e.reps >> e.series;
    return is;
}

exercise &exercise::operator=(const exercise &e) = default;
