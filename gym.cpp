#include "gym.h"
#include "location.h"
#include "clock_time.h"
#include "too_many_clients.h"
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
    if(clients.size() == client_limit)
        throw too_many_clients();

    clients.push_back(client);
}

void gym::remove_clients()
{
    clients.clear();
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
    cout << "\n";

    return cout;
}

istream& operator>> (istream &is, gym &g)
{
    is >> g.name >> g.address >> g.open_time >> g.close_time >> g.space;
    return is;
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

void gym::total_income()
{
    int total = 0;

    total = clients.size() * membership_price;

    cout << "The gym " << name << " " << "has a total income of " << total << " ron" << "\n";

}

void gym::change_membership_price(int new_price)
{
    membership_price = new_price;
}

void gym :: pros_and_cons()
{
    cout << "Pros:" << "\n";
    cout << "A gym membership grants access to a variety of high-quality exercise equipment. From weight machines and dumbbells, to ellipticals and Stairmasters, there’s everything you need to kick start your fitness journey. " << "\n";
    cout << "Gyms are full of fitness professionals ready and able to provide expert training. If you’re new to exercising, they’re full of knowledge you can tap into that goes well beyond the gym. Not only do they offer workout advice, some can provide tips about healthy eating. Trainers are a built-in support system and can be a valuable resource." << "\n";
    cout << "Exercise classes are a great way to socialize and break a sweat. Classes are fun, engaging, and full of energy. They provide a structured environment that allows you to learn something new alongside your peers. You can meet your fitness goals through dance, yoga, kickboxing, Pilates, and more." << "\n";
    cout << "Cons:" << "\n";
    cout << "Lack of transportation could keep you from the gym and your fitness goals. Public transit is an alternative but it may put a dent in your bank account. There’s also the weather, which can be an unpredictable distraction. It’s hard to stay motivated with six feet of snow outside your door." << "\n";
    cout << "A gym is a communal space where everyone is expected to train in peace. That’s hard to do when there’s no equipment available. Or when your favorite class is full. Overcrowding can be an annoyance that dampens your entire experience. Unfortunately, there are only two solutions: adjust your schedule or move to a different facility." << "\n";
}
