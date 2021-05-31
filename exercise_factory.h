#ifndef TEMA_EXERCISE_FACTORY_H
#define TEMA_EXERCISE_FACTORY_H
#include "exercise.h"

class exercise_factory {

public:

    static exercise biceps() {return exercise("Biceps curl", 12, 3);}
    static exercise triceps() {return exercise("Cable pushdown", 15, 4);}
    static exercise shoulders() {return exercise("Front raise", 20, 6);}
    static exercise quads() {return exercise("Squats", 10, 3);}
    static exercise hamstrings() {return exercise("Air squats", 15, 4);}
    static exercise calves() {return exercise("Calf raise", 30, 6);}
    static exercise abdomen() {return exercise("Crunches", 50, 5);}
    static exercise chest() {return exercise("Bench press", 12, 6);}
};


#endif
