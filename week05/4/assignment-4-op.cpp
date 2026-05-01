// Oscar Perez - Distance Traveled
#include <iostream>

using namespace std;

int main()
{
    // variables
    double distance, speed;
    
    int time_in_hours;
    int count = 1; // we always calculate at least 1 mile


    // introduction 
    cout << endl << "Let's figure out the distance traveled for a vehicle." << endl;
    cout << "We will start by gathering some information:" << endl;

    cout << "\t1. What is the speed of the vehicle in mph? --> ";
    cin >> speed;

    while (speed <= 0)
    {
        cout << "Please enter a number greater than 0! ";
        cin >> speed;
    }

    cout << "\t2. How many hours has it traveled? --> ";
    cin >> time_in_hours;

    while (time_in_hours <= 0)
    {
        cout << "Please enter a number greater than 0! ";
        cin >> time_in_hours;
        cout << endl;
    }

    // displaying header
    cout << endl << "Hour\t\tDistance Traveled" << endl;
    cout << "------------------------------------------" << endl;
    // main loop

    for (int hours_elapsed = 1; hours_elapsed <= time_in_hours; hours_elapsed++)
    {
        distance += speed * count; // using the count since it is starting with 1.
        
        cout << count << "\t\t" << distance << endl;

        count++;
    }



}