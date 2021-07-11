#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// Prototype functions
void game();
int dice_roll();
int scoreBoard(int roll1, int roll2, int* pScorer);

int main() {
    // Set up old black and green terminal look
    system("color 02");
    
    // Title Banner
    cout << "\t\t\t\t  _________       ___       ________       ________    \n";
    cout << "\t\t\t\t |         \\     |   |     /   __   \\     |        | \n";
    cout << "\t\t\t\t |    __    \\    |   |    /   /  \\   \\    |  ______|\n";
    cout << "\t\t\t\t |   |  \\    |   |   |   |   |    |   |   | |         \n";
    cout << "\t\t\t\t |   |   |   |   |   |   |   |    |___|   | |___       \n";
    cout << "\t\t\t\t |   |   |   |   |   |   |   |            |     |      \n";
    cout << "\t\t\t\t |   |   |   |   |   |   |   |            |     |      \n";
    cout << "\t\t\t\t |   |   |   |   |   |   |   |     ___    |  ___|      \n";
    cout << "\t\t\t\t |   |   |   |   |   |   |   |    |   |   | |          \n";
    cout << "\t\t\t\t |   |__/    |   |   |   |   |    |   |   | |______    \n";
    cout << "\t\t\t\t |          /    |   |    \\   \\__/   /    |        | \n";
    cout << "\t\t\t\t |_________/     |___|     \\________/     |________|  \n\n\n";
    
    // variable to initiate game()
    char startGame;
    
    // loop to receive proper user input for [Y]es or [N]o
    do
    {
        cout << "\tDo you wish to roll?\n";
        cout << "\t[Y]es or [N]o: ";
        cin >> startGame;
    } while (startGame != 'Y' && startGame != 'y' && startGame != 'N' && startGame != 'n');
    
    // if variable confirms yes, initiate game
    if (startGame == 'Y' || startGame == 'y')
    {
        // game() function
        game();
    }

    return 0;
}

// Function for game()
void game() {
    //system("cls");
    
    // Scoreboard variables
    int playerScore = 0;
    int compScore = 0;
    int targetGoal = 25;

    // Die variables to keep value
    int die1;
    int die2;

    // Boolean variables to control game play
    bool wantToPlay = true;
    bool playerRolled = false;
    bool compRolled = true;

    // Loop to keep game going based on user desire to play
    do
    {
        // Check if player or computer rolls
        if (playerRolled == false)
        {
            // Roll two dice to and receive numbers 
            int roll1 = dice_roll();
            int roll2 = dice_roll();
            // playerScore pointer set int scoreBoard parameter
            scoreBoard(roll1, roll2, &playerScore);

            // Display playerScore
            cout << "\tPlayer Score is: " << playerScore << endl << endl;

            // Check if playerScore matches targetGoal
            if (playerScore >= targetGoal)
            {
                char reply;
                cout << "Congradulations!!! You Win.\n";
                cout << "Do you want to play again? [Y]es or [N]o:\n";
                cin >> reply;

                // Should player wish to end, reply will change bool controlling do loop
                if (reply == 'n' || reply == 'N')
                {
                    wantToPlay = false;
                }
                else
                {
                    // Reset scores
                    playerRolled = 0;
                    compScore = 0;
                }
            }

            // Switch turns from player to computer
            playerRolled = true;
            compRolled = false;
            // Sleep for 1 sec
            Sleep(1000);
        }
        else if (compRolled == false)
        {
            // Roll two dice to and receive numbers 
            int roll1 = dice_roll();
            int roll2 = dice_roll();
            // playerScore pointer set int scoreBoard parameter
            scoreBoard(roll1, roll2, &compScore);

            cout << "\tComputer Score is: " << compScore << endl << endl;

            // Check if compScore matches targetGoal
            if (compScore >= targetGoal)
            {
                char reply;
                cout << "Better luck next time.\n";
                cout << "Do you want to play again? [Y]es or [N]o:\n";
                cin >> reply;

                // Should player wish to end, reply will change bool controlling do loop
                if (reply == 'n' || reply == 'N')
                {
                    wantToPlay = false;
                }
                else
                {
                    // Reset scores
                    playerRolled = 0;
                    compScore = 0;
                }
            }

            // Switch turns from computer to player
            playerRolled = false;
            compRolled = true;
            // Sleep for 1 sec
            Sleep(1000);
        }

    } while (wantToPlay == true);

    return;
}

int dice_roll()
{
    // Return random number between 1-6
    return (rand() % 6 + 1);
}

int scoreBoard(int die1, int die2, int* pScorer)
{
    // Take random numbers from die1 and die2 and combine for score
    int total;
    total = die1 + die2;
    // Add new score to scorers points total via pointer
    *pScorer = *pScorer + total;

    // Return pointer
    return *pScorer;
}