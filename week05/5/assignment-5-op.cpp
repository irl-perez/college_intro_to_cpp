#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // set seed for true trandom
    unsigned seed = time(0);
    srand(seed);

    // variables
    const int CORRECT_NUMBER = 1 + rand() % 1000;
    int player_guess // leaving with no value
        ,number_of_guesses = 0;
    
    // display instructions
    cout << endl << "Let's play game! ψ(｀∇´)ψ" << endl;
    cout << "I will come up with a number..." << endl;
    cout << "... and you can't leave until you guess it!" << endl;
    cout << "Here's what you need to know:" << endl;
    cout << "\t- You must guess a number between 1 and 1000 (yes that includes 1 and 1000)..." << endl;
    cout << "\t- Every time you guess I will tell you if the correct number is lower or higher" << endl;
    cout << "\t- You can guess as many times as you want!" << endl;

    cout << "...good luck..." << endl;

    // loop
    while (player_guess != CORRECT_NUMBER)
    {
        cout << endl << "guess: ";
        cin >> player_guess;

        if (player_guess < 0)
            cout << "... i said a number between 1 and 1000... guess again" << endl;
        else if (player_guess > 1000)
            cout << "... i said a number between 1 and 1000... guess again" << endl;
        else if (player_guess == CORRECT_NUMBER)
            cout << "Wow that's actually right! Congrats!" << endl; // forgot to add this line in pseudocode. 
        else if (player_guess < CORRECT_NUMBER)
            cout << "That guess was too low!" << endl;
        else if (player_guess > CORRECT_NUMBER)
            cout << "That guess was too high!" << endl;
        
        number_of_guesses++;

    }

    cout << "That only took you " << number_of_guesses << " guesses..." << endl;


}