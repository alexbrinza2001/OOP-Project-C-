#include "gym.h"
#include "too_many_clients.h"
#include <iostream>
#include <string>
using namespace std;

location gym::get_address() {return address;}

clock_time gym::get_open() {return open_time;}

clock_time gym::get_close() {return close_time;}

string gym::get_name() {return name;}

int gym::get_space() const{return space;}

void gym::add_client(string &client)
{
    if(clients.size() == client_limit)
        throw too_many_clients();

    clients.push_back(client);
}

void gym::remove_clients()
{
    clients.clear();
}

bool gym::search_client(string &client)
{
    int s = clients.size();
    for(int i = 0; i < s; ++i)
        if(clients[i] == client) return true;
    return false;
}

ostream& operator<< (ostream &os, const gym &g)
{
    os << "Name: " << g.name << "\n";
    os << "Address" << "\n" << g.address << "\n";
    os << "Program: " << g.open_time << " - " << g.close_time << "\n";
    os << "Space: " << g.space << "\n";
    os << "Client list: ";
    for(int i = 0; i < g.clients.size(); ++i)
        os << g.clients[i] << " ";
    os << "\n";

    return os;
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
    int total;

    total = (int) clients.size() * membership_price;

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

bool gym :: operator >(gym& g) const
{
    return this->get_space() > g.get_space();
}
