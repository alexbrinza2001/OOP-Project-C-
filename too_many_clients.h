#ifndef TEMA_TOO_MANY_CLIENTS_H
#define TEMA_TOO_MANY_CLIENTS_H
#include <iostream>
using namespace std;

class too_many_clients : public exception
{

public:

    const char * what() const noexcept override
    {
        return "Too many clients";
    }
};


#endif
