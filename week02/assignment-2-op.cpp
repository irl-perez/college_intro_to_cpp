// Oscar Perez - Stock Comission Calculator

#include <iostream>
#include <iomanip> // manipulate the io stream

using namespace std;

int main(){

    // fixed always shows decimals
    // setprecision say how many digits
    cout << fixed << setprecision(2); // this is good for currency. 

    // variables
    const double COMMISSION_PERCENTAGE = 0.02;
    double numberOfShares,
            pricePerShare,
            brokersCommission,
            stockSubtotal,
            grandTotal;
    
    // userinput
    cout << endl << "Please enter the number of  shares: ";
    cin >> numberOfShares;

    cout << "Please enter the price per share: ";
    cin >> pricePerShare;

    // calculations
    stockSubtotal = numberOfShares * pricePerShare;

    brokersCommission = stockSubtotal * COMMISSION_PERCENTAGE;

    grandTotal = stockSubtotal + brokersCommission;

    //output to the user
    cout << endl << "For " << numberOfShares << " share(s) at " << pricePerShare;
    cout << " the price is: $" << stockSubtotal << endl;

    cout << setprecision(0); // flip precision for the percentage.
    cout << endl << "For a comission fee at " << COMMISSION_PERCENTAGE * 100;
    cout << setprecision(2);
    cout << "% will be: $" << brokersCommission << endl;
    

    cout << endl << "Your grand total is: $" << grandTotal << endl;

    cout << "Thank you for using this program!";

    cout << "Four " << "score ";
    cout << "and " << "seven\n";
    cout << "years" << "ago" << endl;

}