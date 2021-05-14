#ifndef TEMA_POWERLIFTING_GYM_H
#define TEMA_POWERLIFTING_GYM_H
#include "gym.h"

class powerlifting_gym : public gym{

public:

    powerlifting_gym()
    {
        change_membership_price(90);
    }

    void pros_and_cons()
    {
        cout << "Pros:" << "\n";
        cout << "Bone density improvements" << "\n";
        cout << "Improvements to functional strength" << "\n";
        cout << "Performance-based training goals" << "\n";
        cout << "Cons:" << "\n";
        cout << "Neglect of cardio exercise" << "\n";
        cout << "Lack of overall balanced nutrition" << "\n";
    }
};


#endif
