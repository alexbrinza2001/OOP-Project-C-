#ifndef TEMA_CROSSFIT_GYM_H
#define TEMA_CROSSFIT_GYM_H
#include "gym.h"

class crossfit_gym : public gym{

public:

    crossfit_gym()
    {
        change_membership_price(100);
    }

    void pros_and_cons()
    {
        cout << "Pros:" << "\n";
        cout << "Nutrition" << "\n";
        cout << "Affordability" << "\n";
        cout << "Portability" << "\n";
        cout << "Cons:" << "\n";
        cout << "Frequent Injury" << "\n";
        cout << "Challenging Technique" << "\n";
        cout << "Peer Pressure" << "\n";
    }

};


#endif
