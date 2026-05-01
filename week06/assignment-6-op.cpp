// // Oscar Perez - Test Average and Grade - 2026-03-06
#include <iostream>
using namespace std;

char determineGrade(double);
double calcAverage(double, double, double, double, double);

int main()
{
    // a loop would be nice, but we need to send find arguments to our function.
    double score1, score2, score3, score4, score5;

    cout << "This program will help you see letter grades and the average of five scores." << endl;

    cout << "Please enter score 1: ";
    cin >> score1;
    cout << determineGrade(score1);

    cout << endl << endl << "Please enter score 2: ";
    cin >> score2;
    cout << determineGrade(score2);

    cout << endl << endl << "Please enter score 3: ";
    cin >> score3;
    cout << determineGrade(score3);

    cout << endl << endl << "Please enter score 4: ";
    cin >> score4;
    cout << determineGrade(score4);

    cout << endl << endl <<  "Please enter score 5: ";
    cin >> score5;
    cout << determineGrade(score5);

    cout << endl << endl << "average score: " << calcAverage(score1, score2, score3, score4, score5);

    return 0;

}

char determineGrade(double score)
{
    char letter_grade;

    if (score <= 59)
        letter_grade = 'F';
    else if (score <= 69)
        letter_grade = 'D';
    else if (score <= 79)
        letter_grade = 'C';
    else if (score <= 89)
        letter_grade = 'B';
    else
        letter_grade = 'A';
    
    return letter_grade;
}

double calcAverage(double score1, double score2, double score3, double score4, double score5)
{
    return ((score1 + score2 + score3 + score4 + score5) / 5);
}