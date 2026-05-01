// Oscar Perez - Vowels and Consonants
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isVowl(char c);
int countVowls (const char* sentence);
int countConsonants (const char* sentence);

int main ()
{
    const int SIZE = 100;
    char menuSelection = ' ';
    char sentence[SIZE]; // c-strings are just arrays

    
    cout << endl << "The following program will tell you the number of vowels or consontants in a sentence!" << endl;

    cout << "Enter a sentence (100 character max): ";
    cin.getline(sentence, SIZE);

    while (menuSelection != 'd')
    {
        cout << "select one of the options:" << endl;
        cout << "A - Count Vowels" << endl;
        cout << "B - Count Consonants" << endl;
        cout << "C - Enter another string" << endl;
        cout << "D - Exit" << endl;

        cin >> menuSelection;

        menuSelection = tolower(menuSelection);

        switch (menuSelection)
        {
            case 'a':
                cout << "Number of vowels: " << countVowls(sentence) << endl;
                break;
            
            case 'b':
                cout << "Number of Consonants: " << countConsonants(sentence) << endl;
                break; 
            
            case 'c':
                cout << "Enter a new string: ";
                cin.ignore();
                cin.getline(sentence, SIZE);
                break;
            
            case 'd':
                cout << "Thanks for using this program!" << endl;
                break; 

        }
    }
}

bool isVowl(char c)
{
    c = tolower(c); // lower the character to compare
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowls (const char* sentence)
{
    int counter = 0;
    for (int i = 0; sentence[i]!= '\0'; i++)
    {
        if (isVowl(sentence[i]))
            counter+= 1;
    }

    return counter;
}


int countConsonants (const char* sentence)
{
    int counter = 0;
    for (int i = 0; sentence[i]!= '\0'; i++)
    {
        if (!isVowl(sentence[i]) && isalpha(sentence[i]))
            counter+= 1;
    }

    return counter;
}

