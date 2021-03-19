#include <iostream>
#include <string>
#include <vector>
#include "location.h"
#include "clock_time.h"
#include "date.h"
#include "person.h"
#include "gym.h"
#include "exercise.h"
#include "trainer.h"
using namespace std;

vector < string > a;
string b;

int main()
{
    trainer t;
    trainer s;
    cin >> t;
    cin >> b;
    t.add_day(b);
    //t.add_day("Friday");
    //t.add_type("Arms");
    //t.add_type("Trx");
    s = t;
    cout << s;
    return 0;
}
