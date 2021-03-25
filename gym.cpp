#include "gym.h"
#include "location.h"
#include "clock_time.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void gym::set_gym(string _name, location _address, clock_time open, clock_time close, vector < string > _clients, int _space)
{
    name = _name;
    address = _address;
    open_time = open;
    close_time = close;
    clients.clear();
    int s = _clients.size();
    for(int i = 0; i < s; ++i)
        clients.push_back(_clients[i]);
    space = _space;
}

location gym::get_address() {return address;}

clock_time gym::get_open() {return open_time;}

clock_time gym::get_close() {return close_time;}

string gym::get_name() {return name;}

int gym::get_space() {return space;}

void gym::add_client(string client)
{
    clients.push_back(client);
}

bool gym::search_client(string client)
{
    int s = clients.size();
    for(int i = 0; i < s; ++i)
        if(clients[i] == client) return 1;
    return 0;
}

ostream& operator<< (ostream &cout, const gym &g)
{
    cout << "Name: " << g.name << "\n";
    cout << "Address" << "\n" << g.address << "\n";
    cout << "Program: " << g.open_time << " - " << g.close_time << "\n";
    cout << "Space: " << g.space << "\n";
    cout << "Client list: ";
    for(int i = 0; i < g.clients.size(); ++i)
        cout << g.clients[i] << " ";

    return cout;
}

istream& operator>> (istream &cin, gym &g)
{
    cin >> g.name >> g.address >> g.open_time >> g.close_time >> g.space;
    return cin;
}

gym &gym::operator=(const gym &g)
{
    this->name = g.name;
    this->address = g.address;
    this->open_time = g.open_time;
    this->close_time = g.close_time;
    this->space = g.space;
    int s = g.clients.size();
    this->clients.clear();
    for(int i  = 0; i < s; ++i)
        this->clients.push_back(g.clients[i]);
    return *this;
}
