#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

//Function Prototype
void wordScramble();

int main()
{
    wordScramble();

    return 0;
}

void wordScramble() {
    // Constant variable for avaiable attempts at start
    const int START_ATTEMPTS = 3;
    // String variable to hold user answer
    string guess;
    // Boolean variable to control program status
    bool isPlaying = true;

    enum fields { WORD, HINT, NUM_FIELD };
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELD] =
    {
        {"soda", "Fizzy drink some call pop"},
        {"home", "Is where the heart is"},
        {"stew", "Meat, veggies, and broth"},
        {"rain", "Guns N' Roses November ____"},
        {"mark", "Another word for spot"},
        {"flee", "To run away"},
        {"news", "Often considered fake, these days"},
        {"lade", "Nautical term for a load on a vessel"},
        {"fair", "To be legitimate"},
        {"skin", "Often, a protective layer around an object"}
    };


    do {
        // Integer variable to be manipulated during program run
        int attempts = START_ATTEMPTS;

        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand() % NUM_WORDS);
        // Word to be guessed
        string keyword = WORDS[choice][WORD];
        // Hint to be displayed if needed
        string keyHint = WORDS[choice][HINT];

        string jumble = keyword;
        int length = jumble.size();

        for (int i = 0; i < length; i++) {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }

        cout << "\t\t\t\t\tCode Breaker Training Simulation Program\n\n";
        cout << "\tUnscramble the letters to make the word proper.\n";
        cout << "\tEnter \'h\' for a hint.\n";
        cout << "\tEnter \'r\' to restart.\n";
        cout << "\tEnter \'q\' to close the program.\n\n";
        
        do {
            cout << "\tKeyword is: " << jumble << "\n";
            cout << "\tYou have " << attempts << " remaining\n\n";
            cout << "\tYour guess: ";
            cin >> guess;

            if (guess == keyword) {
                cout << "\tAccess Granted!!!\n";
                Sleep(1000);
                system("cls");
            }
            else if (guess == "r") {
                system("cls");
                break;
            }
            else if (guess == "q") {
                isPlaying = false;
                break;
            }
            else if (guess == "h") {
                cout << "\t" << keyHint << "\n\n";
            }
            else {
                attempts--;
                cout << "\tEntry incorrect, please try again.\n\n";
            }

            if (attempts == 0)
            {
                system("cls");
            }
        } while ((guess != keyword) && (guess != "q") && (guess != "r") && (attempts > 0));
    } while (isPlaying == true);

    return;
}