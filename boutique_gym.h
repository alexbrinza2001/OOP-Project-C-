#ifndef TEMA_BOUTIQUE_GYM_H
#define TEMA_BOUTIQUE_GYM_H
#include "gym.h"

class boutique_gym : public gym{

public:

    boutique_gym()
    {
        change_membership_price(150);
    }

    void pros_and_cons() override
    {
        cout << "Pros:" << "\n";
        cout << "Highly trained instructors" << "\n";
        cout << "Camaraderie and community" << "\n";
        cout << "Focus on one form of training" << "\n";
        cout << "Cons:" << "\n";
        cout << "Limited class type" << "\n";
        cout << "Scheduling limitations" << "\n";
    }

};


#endif
