// Oscar Perez - Rainfall Stats
#include <iostream>
#include <iomanip>

using namespace std;

// prototypes
double calcTotalRain(double nums[], int SIZE);
double calcAvgMonthlyRain(double nums[], const int SIZE);
string findRainestMonth(double nums[], const string months[], const int SIZE);
string findDriesttMonth(double nums[], const string months[], const int SIZE);


int main()
{
    // variables 
    const int TOTAL_MONTHS = 12;

    const string MONTHS[] = {"January", "February", "March", // we could specify size or let cpp figure it out
                            "April", "May", "June", 
                            "July", "August", "September", 
                            "October", "November", "December"};
    
    double rainfall[TOTAL_MONTHS]; // array with 12 open elements

    // prompt
    cout << "This program will help you calculate rainfall statistics over 12 month period." << endl << endl;
    
    // loop to prompt the user for rainfall
    int index = 0; // keep track of current progress
    for (string month : MONTHS) // range base loop to use the month name
    {
        cout << "Please enter the rainfall for " << month << ": ";
        cin >> rainfall[index];
        index += 1;
    }

    cout << endl;
    
    cout << "Total rainfall: " <<  calcTotalRain(rainfall, TOTAL_MONTHS) << endl; 
    cout << "Average rainfall per month: " << calcAvgMonthlyRain(rainfall, TOTAL_MONTHS) << endl;
    cout << "Rainest Month: " << findRainestMonth (rainfall,MONTHS,TOTAL_MONTHS) << endl;
    cout << "Driest Month: " << findDriesttMonth(rainfall,MONTHS,TOTAL_MONTHS) << endl;

    
    


    return 0;    
}

double calcTotalRain(double nums[], int SIZE)
{
    double totalRain = 0.0;
    for (int index = 0; index < SIZE; index++)
        totalRain += nums[index];
    
    return totalRain;
}

double calcAvgMonthlyRain(double nums[], const int SIZE)
{   
    double avgRain = 0.0;
    double totalRain = calcTotalRain(nums, SIZE); // to avoid building the same function, call the one we already built
    avgRain = totalRain / SIZE;
    return avgRain;
}

string findRainestMonth(double nums[], const string MONTHS[], const int SIZE)
{
    double highestRain = nums[0];
    int index = 0;
    for (int counter = 1; counter < SIZE; counter++)
    {
        if (nums[counter] > highestRain)
        {
            highestRain = nums[counter];
            index = counter;
        }
    }
    
    return MONTHS[index];
}

string findDriesttMonth(double nums[], const string MONTHS[], const int SIZE)
{
    double highestRain = nums[0];
    int index = 0;
    for (int counter = 1; counter < SIZE; counter++)
    {
        if (nums[counter] < highestRain)
        {
            highestRain = nums[counter];
            index = counter;
        }
    }
    
    return MONTHS[index];
}