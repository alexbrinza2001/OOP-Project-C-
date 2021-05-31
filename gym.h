#ifndef TEMA_GYM_H
#define TEMA_GYM_H
#include <iostream>
#include <vector>
#include <string>
#include "location.h"
#include "clock_time.h"
using namespace std;

class gym{
    string name;
    location address;
    clock_time open_time;
    clock_time close_time;
    vector < string > clients;
    int space = 0;
    int membership_price = 130;
    static const int client_limit = 20;

public:

    gym() = default;

    gym(string &Name, location &Address, clock_time &open, clock_time &close, vector < string > &Clients, int &Space)
    {
        name = Name;
        address = Address;
        open_time = open;
        close_time = close;
        clients.clear();
        int s = Clients.size();
        for(int i = 0; i < s; ++i)
            clients.push_back(Clients[i]);
        space = Space;
    }

    virtual ~gym() = default;

    string get_name();

    void remove_clients();

    location get_address();

    clock_time get_open();

    clock_time get_close();

    int get_space() const;

    void add_client(string &client);

    bool search_client(string &client);

    friend ostream& operator<< (ostream &cout, const gym &g);

    friend istream& operator>> (istream &is, gym &g);

    gym &operator=(const gym &g);

    virtual void total_income();

    void change_membership_price(int new_price);

    virtual void pros_and_cons();

    bool operator >(gym& g) const;

};

#endif
