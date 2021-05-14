#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
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

ifstream in("input");

void initialize_data(vector < gym > &gym_list, vector < trainer > &trainer_list)
{
    gym gym_data;
    int client_number, days_number, types_number, gym_number, trainer_number;
    string client, day, type;
    trainer trainer_data;

    in >> gym_number;

    for(int i = 0; i < gym_number; ++i)
    {
        in >> gym_data;
        in >> client_number;
        for(int j = 0; j < client_number; ++j)
        {
            in >> client;
            gym_data.add_client(client);
        }

        gym_list.push_back(gym_data);

        gym_data.remove_clients();
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

void read_clients(vector < client > &clients)
{
    client client_data;
    int days_number, client_count;
    string day;

    in >> client_count;

    for(int i = 0; i < client_count; ++i)
    {
        in >> client_data;
        in >> days_number;
        for(int i = 0; i < days_number; ++i)
        {
            in >> day;
            client_data.add_day(day);
        }

        clients.push_back(client_data);
        client_data.remove_days();
    }
}

bool comp1(trainer A, trainer B)
{
    return ( (float) 1.0 * A.get_experience() / 1.0 * A.get_price() ) < ( (float) 1.0 * B.get_experience() / 1.0 * B.get_price() );
}

void find_trainer(vector < client > clients, vector < trainer > trainer_list)
{
    bool gasit;
    vector < trainer > possible_trainers;

    for(int i = 0; i < clients.size(); ++i)
    {
        int ok = 0;
        possible_trainers.clear();

        for(int j = 0; j < trainer_list.size(); ++j)
        {
            for(int k = 0; k < trainer_list[j].get_days().size(); ++k)
                for(int l = 0; l < clients[i].get_days().size(); ++l)
                    if(trainer_list[j].get_days()[k] == clients[i].get_days()[l])
                    {
                        ok = 1;
                        possible_trainers.push_back(trainer_list[j]);
                    }
        }

        if(ok == 0)
        {
            cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " did not find any trainer." << "\n";
            continue;
        }

        sort(possible_trainers.begin(), possible_trainers.end(), comp1);

        gasit = 0;

        try
        {
            for(int i = 0; i < possible_trainers.size(); ++i)
            {
                int limit = possible_trainers[i].get_client_limit();
                int client_count = possible_trainers[i].get_client_count();

                if(client_count == limit) continue;
                else
                {
                    gasit = 1;
                    throw i;
                    break;
                }
            }

            throw gasit;
        }

        catch(int counter)
        {
            cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " chose " << possible_trainers[counter].get_first_name() << " " << possible_trainers[counter].get_last_name() << " as a trainer." << "\n";
            possible_trainers[counter].add_client(clients[i]);
        }

        catch(bool found)
        {
            if(found == 0)
                cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " did not find any trainer." << "\n";
        }
    }
}

bool comp2(gym A, gym B)
{
    return A.get_space() > B.get_space();
}

void find_gym(vector < client > clients, vector < gym > gym_list)
{
    vector < gym > possible_gyms;

    for(int i = 0; i < clients.size(); ++i)
    {
        int ok = 0;
        possible_gyms.clear();

        for(int j = 0; j < gym_list.size(); ++j)
            if(clients[i].get_city() == gym_list[j].get_address().get_city())
            {
                ok = 1;
                possible_gyms.push_back(gym_list[j]);
            }

        if(ok == 0)
        {
            cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " did not find any gym" << "\n";
            continue;
        }

        sort(possible_gyms.begin(), possible_gyms.end(), comp2);

        cout << clients[i].get_first_name() << " " << clients[i].get_last_name() << " chose " << possible_gyms[0].get_name() << " as their gym." << "\n";
    }
}

void gym_advice()
{
    string gym_type;

    in >> gym_type;

    if(gym_type == "Boutique")
    {
        gym* g;
        boutique_gym b;
        g = &b;
        g->pros_and_cons();
    }

    if(gym_type == "Crossfit")
    {
        gym* g;
        crossfit_gym b;
        g = &b;
        g->pros_and_cons();
    }

    if(gym_type == "Powerlifting")
    {
        gym* g;
        powerlifting_gym b;
        g = &b;
        g->pros_and_cons();
    }
}

int main()
{
    vector < gym > gym_list;
    vector < trainer > trainer_list;
    vector < client > clients;
    int task;

    initialize_data(gym_list, trainer_list);
    read_clients(clients);
/*
    for(int i = 0; i < gym_list.size(); ++i)
        cout << gym_list[i] << " ";
    cout << "\n";
    for(int i = 0; i < trainer_list.size(); ++i)
        cout << trainer_list[i] << " ";
    cout << "\n";
    for(int i = 0; i < clients.size(); ++i)
        cout << clients[i] << " ";
    cout << "\n";
*/
    in >> task;
    if(task == 1) find_trainer(clients, trainer_list);
    if(task == 2) find_gym(clients, gym_list);
    if(task == 3) gym_advice();

    return 0;
}