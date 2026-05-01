// Oscar Perez - corp sales
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <fstream>


using namespace std;

// structure
struct DivisionInfo
{
    string div_name;
    double q1Sales;
    double q2Sales;
    double q3Sales;
    double q4Sales;
    double totalAnnualSales;
    double avgQuarterlySales;

};

// prototypes
void programIntro();
void userDataIngestion(DivisionInfo DivisionList[], int total_divs);
void displayAllDivisionInfo(const DivisionInfo the_division);

void processAllDivison(DivisionInfo DivisonList[], int total_divs);
void calcTotalSales(DivisionInfo &the_division);
void calcAvgQuarterlySales(DivisionInfo &the_division);
DivisionInfo fileDataIngestion(string fileName);



int main ()
{

    const bool DEBUG_MODE = false; // using debug to test values without retyping
    const bool FILE_MODE = true; // added a new debug flag to revert behavior
    int total_divisions = 4; // not const so i can debug with fake data
    
    DivisionInfo DivisionList[total_divisions]; // i liked the idea of an array after watching the lecture.
    string fileList[total_divisions]; 

    // new file every time.
    ofstream newFile("reportFile.txt", ios::trunc);
    newFile.close();



    if (DEBUG_MODE) // adding a debug mode so i don't have to enter data. 
    {
        DivisionInfo d1 =
        {
            "North",
            6000.00,
            60000.12,
            12000.50,
            2000.03,
            0,
            0
        };

        DivisionInfo d2 =
        {
            "East",
            2.50,
            60.30,
            800.30,
            39567.20,
            0,
            0
        };

        DivisionInfo d3 = 
        {
            "South",
            583.12,
            466.05,
            4683.36,
            66666.66,
            0,
            0

        };

        DivisionInfo d4 = 
        {
            "West",
            69.38,
            485.30,
            134.36,
            44.12,
            0,
            0
        };

        DivisionList[0] = d1;
        DivisionList[1] = d2;
        DivisionList[2] = d3;
        DivisionList[3] = d4;
    }

    if (FILE_MODE) // easy way to input file names
    {
        // filenames:
        string d1_name = "d1.txt";
        string d2_name = "d2.txt";
        string d3_name = "d3.txt";
        string d4_name = "d4.txt";

        fileList[0] = d1_name;
        fileList[1] = d2_name;
        fileList[2] = d3_name;
        fileList[3] = d4_name;
        
    }

    cout << endl; // break away from first line 
    if (!DEBUG_MODE && !FILE_MODE) // added the flag here
        userDataIngestion(DivisionList, total_divisions);
    else
        for(int i = 0; i < total_divisions; i+=1)
            DivisionList[i] = fileDataIngestion(fileList[i]); // call the file ingestion function - append struct to list


    
    processAllDivison(DivisionList, total_divisions);

    int i = 0; 
    do
    {
        displayAllDivisionInfo(DivisionList[i]);
        i += 1;
        cout << endl; // spacer between divisons
    }
    while(i < total_divisions);
    

}

// i decided to break down my code into pieces. 

void programIntro() // trying to break up code, put pieces together later
{
    cout << "This program will calculate the total annual sales" << endl; 
    cout << "and average quarterly sales for your four divisions." << endl;
}

void userDataIngestion(DivisionInfo DivisionList[], int total_divs) // passing the address of structure array
{ // user enters only necessary data
    
    cout << "You will enter data " << total_divs << " time(s)." << endl << endl;


    int i = 0;
    do // do loop at least onces
    {
        cout << "Division Name: ";
        getline(cin, DivisionList[i].div_name);

        cout << "Q1 Sales: ";
        cin >> DivisionList[i].q1Sales;

        cout << "Q2 Sales: ";
        cin >> DivisionList[i].q2Sales;

        cout << "Q3 Sales: ";
        cin >> DivisionList[i].q3Sales;

        cout << "Q4 Sales: ";
        cin >> DivisionList[i].q4Sales;
        cin.ignore();

        DivisionList[i].totalAnnualSales = 0;
        DivisionList[i].avgQuarterlySales = 0;

        i += 1;
        cout << endl;
        


    } while (i < total_divs);

}

void displayAllDivisionInfo(const DivisionInfo the_division) // easy way to dispaly all information for divisions
{
    ofstream outFile("reportFile.txt", ios::out | ios::app); // output and append
    cout << fixed << setprecision(2) << showpoint;

    cout << left << setw(40) << "Division Name: " << the_division.div_name << endl;
    outFile << left << setw(40) << "Division Name: " << the_division.div_name << endl;

    cout << left << setw(40) << "Q1 sales: " << "$" << the_division.q1Sales << endl;
    outFile << left << setw(40) << "Q1 sales: " << "$" << the_division.q1Sales << endl;

    cout << left << setw(40) << "Q2 sales: " << "$" << the_division.q2Sales << endl;
    outFile << left << setw(40) << "Q2 sales: " << "$" << the_division.q2Sales << endl;

    cout << left << setw(40) << "Q3 sales: " << "$" << the_division.q3Sales << endl;
    outFile << left << setw(40) << "Q3 sales: " << "$" << the_division.q3Sales << endl;

    cout << left << setw(40) << "Q4 sales: " << "$" << the_division.q4Sales << endl;
    outFile << left << setw(40) << "Q4 sales: " << "$" << the_division.q4Sales << endl;

    cout << left << setw(40) << "Total Annual Sales: " << "$" << the_division.totalAnnualSales << endl;
    outFile << left << setw(40) << "Total Annual Sales: " << "$" << the_division.totalAnnualSales << endl;

    cout << left << setw(40) << "Average Quarterly Sales: " << "$" << the_division.avgQuarterlySales << endl;
    outFile << left << setw(40) << "Average Quarterly Sales: " << "$" << the_division.avgQuarterlySales << endl;
    outFile << endl; // extra end line to the outfile

    outFile.close();

}

void processAllDivison(DivisionInfo DivisonList[], int total_divs){ // we call our all our calc functions with this call

    for(int i = 0; i < total_divs; i+=1)
    {
        calcTotalSales(DivisonList[i]);
        calcAvgQuarterlySales(DivisonList[i]);
    }
}

void calcTotalSales(DivisionInfo &the_division) // sums all q sales and adds back to the structure variable
{
    the_division.totalAnnualSales += the_division.q1Sales;
    the_division.totalAnnualSales += the_division.q2Sales;
    the_division.totalAnnualSales += the_division.q3Sales;
    the_division.totalAnnualSales += the_division.q4Sales;
}

void calcAvgQuarterlySales(DivisionInfo &the_division) // look at total sales then divided by four, add back to structure
{
    the_division.avgQuarterlySales =  the_division.totalAnnualSales / 4;
}

DivisionInfo fileDataIngestion(string fileName)
{
    ifstream inputFile(fileName);

    if(inputFile.fail())
    {
        cout << "ERROR WITH FILE!" << endl;
        exit(EXIT_FAILURE);
    }

    DivisionInfo currentDiv;

    while(!inputFile.eof())
    { // had to change the logic bc of data types
        string line;
        getline(inputFile, line);
        currentDiv.div_name = line;

        getline(inputFile, line);
        currentDiv.q1Sales = stof(line);

        getline(inputFile, line);
        currentDiv.q2Sales = stof(line);

        getline(inputFile, line);
        currentDiv.q3Sales = stof(line);

        getline(inputFile, line);
        currentDiv.q4Sales = stof(line);

        currentDiv.totalAnnualSales = 0;
        currentDiv.avgQuarterlySales = 0;
    }
    inputFile.close();

    return currentDiv;


}




