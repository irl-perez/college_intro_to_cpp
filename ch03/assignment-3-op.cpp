// Oscar Perez - Monthly Payment Calculator for Loan

#include <iostream>
#include <iomanip>
#include <cmath>                    // allows for exponents

using namespace std;

int main(){

    cout << fixed << setprecision(2);

    int numberOfPayments; // assuming only whole numbers, 60, 70, 80, etc.  term lengths

    // variables
    double  loanAmount,			    // user input
            annualInterestRate,     // user input
            monthlyInterestRate,    // user input
            monthlyPayment,		    // formula
            grandTotal,			    // monthlyPayment * numberOfPayments?
            totalInterestedPaid;     // grandTotal - loanAmount

    string usersName;

    // introduction
    cout << endl;
    cout << "Welcome to your personal monthly loan calculator!" << endl;
    cout << "We'll make this process easy by following these easy steps: " << endl;
    cout << "\t1. Collect information about your loan." << endl;
    cout << "\t2. Runs some calculations." << endl;
    cout << "\t3. Show you your loan information!" << endl << endl;


    // userinput
    cout << "Let's get started, what is your name: ";
    getline(cin, usersName);

    cout << "Please enter your total loan amount (known as the principle): ";
    cin >> loanAmount;
    cout << endl;

    cout << "Great! Now enter your annual interest rate: ";
    cin >> annualInterestRate;
    cout << endl;

    cout << "Finally, I'll need the number of payments (commonly known as the term): ";
    cin >> numberOfPayments;
    cout << endl;

    // calculations
    monthlyInterestRate = (annualInterestRate / 100) / 12; // input assumed to be a literal percent like: 6.2%,

    monthlyPayment = ((monthlyInterestRate * pow(1+monthlyInterestRate, numberOfPayments)) / ((pow(1+monthlyInterestRate, numberOfPayments) - 1))) * loanAmount;

    grandTotal = monthlyPayment * numberOfPayments;

    totalInterestedPaid = grandTotal - loanAmount;

    // output
    cout << "Awesome! Thanks for the information. I ran the numbers and I have your loan information." << endl;
    cout << "When you're ready just hit \"enter\" or \"return\"..." << endl;
    cin.ignore(); // since we pressed enter above, there's still a new line in the keyboard buffer
    cin.get();
    cout << endl;
    
    cout << usersName << ", here's everything you need to know:" << endl;
    cout << left << setw(30) << "\t- Loan Amount: " << "$" << loanAmount << endl;


    cout << left << setw(30) << "\t- Monthly Interest Rate: " << monthlyInterestRate << setw(0) << "%" << endl;
    
    cout << setprecision(0);
    cout << left << setw(30) << "\t- Number of Payments: " << numberOfPayments << endl << endl;
    cout << setprecision(2);

    cout << left << setw(30) << "\t- Monthly Payment Amount: " << "$" << monthlyPayment << endl;
    cout << left << setw(30) << "\t- Total Amount to Pay: " << "$" << grandTotal << endl;
    cout << left << setw(30) << "\t- Total Interest Paid: " << "$" << totalInterestedPaid << endl;

    cout << "Thanks for using this program!";



}