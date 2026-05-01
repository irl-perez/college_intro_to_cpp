// Oscar Perez - Find the area of shapes

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

    cout << setprecision(2) << fixed;

    int choice;
    double area;
    const double pi = 3.14159;

    cout << "### Geometry Area Calculator ###" << endl;
    cout << "Please select from one of the options below to find an area of a shape:" << endl;

    cout << "\t1. Circle" << endl;
    cout << "\t2. Rectangle" << endl;
    cout << "\t3. Triangle" << endl;

    cin >> choice;

    switch(choice)
    {
        case 1: // cirlce
            double radius, area;

            cout << endl << "### CIRCLE AREA FINDER ###" << endl;
            cout << "Please enter the radius of your circle: ";
            cin >> radius;

            if (radius < 0)
                cout << "Please run the program again and enter a radius that is greater than 0." << endl;
            else
                area = pi * (pow(radius, 2));
                cout << "The area of your circle is: " << area << endl;
            break;
        
        case 2: // rectangle
            double length, width;

            cout << endl << "### RECTANGLE AREA FINDER ###" << endl;
            cout << "Please enter the length of your rectangle: ";
            cin >> length;
            
            cout << endl;

            cout << "Please enter the width of your rectangle: ";
            cin >> width;    
            
            if (length < 0 or width < 0)
                cout << "Please run the program again and enter a length or width that is greater than 0." << endl;
            else
                area = length * width;
                cout << "The area of your rectangle is: " << area << endl;
            break;

        case 3: // triangle
            double base, height;

            cout << endl << "### TRIANGLE AREA FINDER ###" << endl;
            cout << "Please enter the base of your triangle: ";
            cin >> base;

            cout << endl;

            cout << "Please enter the height of your triangle: ";
            cin >> height;

            if (base < 0 or height < 0)
                cout << "Please run the program again and enter a base or height that is greater than 0." << endl;
            else
                area = base * height * 0.5;
                cout << "The area of your triangle is: " << area << endl;
            break;
            
        default:
            cout << "Please run the program again and select an option between 1-3.";

    }

    cout << endl << "Thank you for using this program!";
}