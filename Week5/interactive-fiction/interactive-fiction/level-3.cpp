/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

#include <iostream>
#include <string>
#include "mission.h"
#include "level-3.h"

using namespace std;

void ch3Solar(string location, int& playerAction)
{
    // New level start dialog
    cout << "\tThe rest of the crew attend to the damage while you check mission heading.\n";
    cout << "\tThe ships computer reveals you are still heading for " + location + ".\n\n";
    cout << "\tAs you begin to approach orbit of " + location + " your ship is bombarded by gamma radiation that exceeds\n";
    cout << "\tyour ships shielding limits.  Your suits are able to withstand the lethal dose of radiation, but\n";
    cout << "\tyour ship's computers are not.\n\n";

    // Player input loop
    do
    {
        // Player interaction dialog
        cout << "\tTemporarily shutdown computer systems to save as much of the ship's computers as possible?\n";
        cout << "\tPress 1 to shutdown ship's computers.\n";
        cout << "\tPress 2 to leave computers running.\n\n";
        // Player input for level 3 action
        cin >> playerAction;

        // Decision results
        if (playerAction == 1)
        {
            // Response dialog for safe choice
            cout << "\tAs the computers power down, the main lights turn off, and emergency lights start up.\n";
            cout << "\tThe solar flare subsides, leaving you and your crew with a dead ship.  Though inertia\n";
            cout << "\twill keep the ship moving for a little while, your crew has just a few hours to get the\n";
            cout << "\tships computers back online before the mission window closes.\n\n";
        }
        else {
            // Create random number between 1 - 10
            int gamble = rand() % 10 + 1;

            // 30% change of success
            if (gamble >= 7)
            {
                // Game over dialog for unsuccessful gamble
                cout << "\tUnfortunately your gamble didn't work and your computer systems are to damaged to continue.\n";
                cout << "\tGAME OVER";
                exit(0);
            }
            else {
                // Dialog for successful gamble
                cout << "\tThat was a bold move.  Fortunately the solar flare did minimal damage to your computer systems.\n\n";
            }
        }
    } while (playerAction < 1 && playerAction >= 2);

    return;
}