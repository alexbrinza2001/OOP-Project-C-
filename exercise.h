#ifndef TEMA_EXERCISE_H
#define TEMA_EXERCISE_H
#include <iostream>
#include <string>
using namespace std;

class exercise{

    string name;
    int reps;
    int series;

public:

    exercise(string Name, int Reps, int Series) : name(move(Name)), reps(Reps), series(Series) {}

    friend ostream& operator<< (ostream &cout, const exercise &e);

    friend istream& operator>> (istream &cin, exercise &e);

    exercise &operator=(const exercise &e);
};


#endif
