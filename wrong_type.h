#ifndef TEMA_WRONG_TYPE_H
#define TEMA_WRONG_TYPE_H
#include <iostream>
using namespace std;

class wrong_type : public exception
{

public:

    const char * what() const noexcept override
    {
        return "This type does not exist!";
    }
};


#endif
