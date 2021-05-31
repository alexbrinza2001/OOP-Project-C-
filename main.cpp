#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include "location.h"
#include "clock_time.h"
#include "date.h"
#include "person.h"
#include "gym.h"
#include "exercise.h"
#include "trainer.h"
#include "client.h"
#include "boutique_gym.h"
#include "crossfit_gym.h"
#include "powerlifting_gym.h"
#include "too_many_clients.h"

template <typename T>

bool compare(T &A, T &B)
{
    return A > B;
}

void initialize_data(ifstream &in, vector< unique_ptr < gym > > &gym_list, vector < trainer > &trainer_list)
{
    string gym_type;
    int client_number, days_number, types_number, gym_number, trainer_number;
    string client, day, type;
    trainer trainer_data;

    in >> gym_number;

    for(int i = 0; i < gym_number; ++i)
    {
        in >> gym_type;

        try {
            if (gym_type == "Boutique")
            {
                boutique_gym gym_data;

                in >> gym_data;
                in >> client_number;

                for (int j = 0; j < client_number; ++j) {
                    in >> client;
                    gym_data.add_client(client);
                }

                gym_list.emplace_back(make_unique<boutique_gym>(gym_data));
            }

            if (gym_type == "Crossfit")
            {
                crossfit_gym gym_data;

                in >> gym_data;
                in >> client_number;

                for (int j = 0; j < client_number; ++j) {
                    in >> client;
                    gym_data.add_client(client);
                }

                gym_list.emplace_back(make_unique<crossfit_gym>(gym_data));
            }

            if (gym_type == "Powerlifting")
            {
                powerlifting_gym gym_data;

                in >> gym_data;
                in >> client_number;

                for (int j = 0; j < client_number; ++j) {
                    in >> client;
                    gym_data.add_client(client);
                }

                gym_list.emplace_back(make_unique<powerlifting_gym>(gym_data));
            }
        }
        catch(too_many_clients &e)
        {
            cout << e.what() << "\n";
        }
    }

    in >> trainer_number;

    for(int i = 0; i < trainer_number; ++i)
    {
        in >> trainer_data;
        in >> days_number;
        for(int j = 0; j < days_number; ++j)
        {
            in >> day;
            trainer_data.add_day(day);
        }
        in >> types_number;
        for(int j = 0; j < types_number; ++j)
        {
            in >> type;
            trainer_data.add_type(type);
        }

        trainer_list.push_back(trainer_data);
        trainer_data.clear_days();
        trainer_data.clear_types();

    }
}

void read_clients(ifstream &in, vector < client > &clients)
{
    client client_data;
    int days_number, client_count;
    string day;

    in >> client_count;

    for(int i = 0; i < client_count; ++i)
    {
        in >> client_data;
        in >> days_number;
        for(int j = 0; j < days_number; ++j)
        {
            in >> day;
            client_data.add_day(day);
        }

        clients.push_back(client_data);
        client_data.remove_days();
    }
}

void find_trainer(vector < client > clients, vector < trainer > trainer_list)
{
    vector < trainer > possible_trainers;

    for(int i = 0; i < clients.size(); ++i)
    {
        int ok = 0;
        possible_trainers.clear();

        for(int j = 0; j < trainer_list.size(); ++j)
        {
            bool gasit = false;

            for(int k = 0; k < trainer_list[j].get_days().size(); ++k)
                if(gasit == 0)
                {
                    for(int l = 0; l < clients[i].get_days().size(); ++l)
                        if(trainer_list[j].get_days()[k] == clients[i].get_days()[l])
                        {
                            ok = 1;
                            possible_trainers.push_back(trainer_list[j]);
                            gasit = true;
                            break;
                        }
                }

        }

        if(ok == 0)
        {
            cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " did not find any trainer." << "\n";
            continue;
        }

        sort(possible_trainers.begin(), possible_trainers.end(), compare<trainer>);

        try
        {
            possible_trainers[0].add_client(clients[i]);
            cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " chose " << possible_trainers[0].get_first_name() << " " << possible_trainers[0].get_last_name() << " as a trainer." << "\n";
        }
        catch(too_many_clients &e)
        {
            cout << e.what() << "\n";
        }

    }
}

void find_gym(vector < client > clients, vector< unique_ptr < gym > > &gym_list)
{
    vector< gym > possible_gyms;

    for(int i = 0; i < clients.size(); ++i)
    {
        int ok = 0;
        possible_gyms.clear();

        for(int j = 0; j < gym_list.size(); ++j)
            if(clients[i].get_city() == gym_list[j]->get_address().get_city())
            {
                ok = 1;
                possible_gyms.emplace_back(*gym_list[j]);
            }

        if(ok == 0)
        {
            cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " did not find any gym" << "\n";
            continue;
        }

        sort(possible_gyms.begin(), possible_gyms.end(), compare<gym>);

        cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " chose " << possible_gyms[0].get_name() << " as their gym." << "\n";
    }
}

void gym_advice(ifstream &in, vector< unique_ptr < gym > > &gym_list)
{
    string gym_name;

    in >> gym_name;

    for(int i = 0; i < gym_list.size(); ++i)
        if(gym_list[i]->get_name() == gym_name)
        {
            gym_list[i]->pros_and_cons();
            break;
        }
}


int main()
{
    ifstream in("input");
    vector< unique_ptr < gym > > gym_list;
    vector < trainer > trainer_list;
    vector < client > clients;
    int task;

    initialize_data(in, gym_list, trainer_list);
    read_clients(in, clients);

    /*for(int i = 0; i < gym_list.size(); ++i)
        cout << *gym_list[i] << " ";
    cout << "\n";
    for(int i = 0; i < trainer_list.size(); ++i)
        cout << trainer_list[i] << " ";
    cout << "\n";
    for(int i = 0; i < clients.size(); ++i)
        cout << clients[i] << " ";
    cout << "\n";*/

    in >> task;
    if(task == 1) find_trainer(clients, trainer_list);
    if(task == 2) find_gym(clients, gym_list);
    if(task == 3) gym_advice(in, gym_list);

    return 0;
}