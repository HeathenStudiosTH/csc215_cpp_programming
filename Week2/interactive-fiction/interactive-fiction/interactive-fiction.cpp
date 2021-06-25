/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

// Header files to import
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

// Namespaces to be used
using namespace std;

// Creating a location class
class Mission {    
    public:
        string location;
        int travelTime;
        void missionLocation(string, int);
};

// Format for Mission class
void Mission::missionLocation(string x, int y) {
    location = x;
    travelTime = y;
}

// Global Variables
Mission myMission;
int playerAction;

// Function to start the game
void startGame() {    
    int playerSelect;

    // Player input loop
    do
    {
        cout << "\tPlease type in your mission location:\n\n";
        cout << "\tPress 1 for Mercury\n";
        cout << "\tPress 2 for Venus\n";
        cout << "\tPress 3 for The Moon\n";
        cout << "\tPress 4 for Mars\n\n";
        cin >> playerSelect;
    } while (playerSelect > 4 && playerSelect < 1);

    // Assigning class variables based on player input
    switch (playerSelect)
    {
    case 1:
        myMission.missionLocation("Mercury", 1260);
        break;
    case 2:
        myMission.missionLocation("Venus", 109);
        break;
    case 3:
        myMission.missionLocation("The Moon", 3);
        break;
    case 4:
        myMission.missionLocation("Mars", 225);
        break;
    default:
        break;
    }
    
    cout << "\tPrepare for blastoff. T minus:\n";
    cout << "\t10\n";
    cout << "\t9\n";
    cout << "\t8\n";
    cout << "\t7\n";
    cout << "\t6\n";
    cout << "\t5\n";
    cout << "\t4\n";
    cout << "\t3\n";
    cout << "\t2\n";
    cout << "\t1\n";
    cout << "\tWe have a successful launch.\n";
    cout << "\tGood luck on your way to " + myMission.location + ", you hear of the radio.\n\n";
    
    return;
}

void ch2Repair() {
    cout << "\tAfter a very exhilerating launch into space, you are on your way to " + myMission.location + "\n\n";
    cout << "\tWhile in your travels to " + myMission.location + ", the ship is straifed by a cloud debree of meteroids.\n";
    cout << "\tThese little micro-meteroids start leaving pin holes into the hull of your ship and a\n\tpuncturing holes in various sections of your ship.\n\n";

    // Player input loop
    do
    {
        cout << "\tWhat do you choose to repair first?\n";
        cout << "\tPress 1 to repair your fuel line.\n";
        cout << "\tPress 2 to repair your hull.\n";
        cout << "\tPress 3 to don your spacesuit.\n";
        cout << "\tPress 4 to repair your communications link.\n\n";
        cin >> playerAction;

        // Decision results
        if (playerAction != 3)
        {
            cout << "\tThe oxygen was sucked out into space, causing you to decompress.\n\tGuess your crewmates will just have to continue on without you.\n";
            cout << "\tGAME OVER\n";
            exit(0);
        }
        else {
            cout << "\tPutting on your spacesuit kept you from decompressing as the oxygen was sucked out of the hull.\n";
            break;
        }
    } while (playerAction > 0 && playerAction <= 4);

    return;
}

void ch3Solar() {
    cout << "\tThe rest of the crew attend to the damage while you check mission heading.\n";
    cout << "\tThe ships computer reveals you are still heading for " + myMission.location + ".\n\n";
    cout << "\tAs you begin to approach orbit of " + myMission.location + " your ship is bombarded by gamma radiation that exceeds\n";
    cout << "\tyour ships shielding limits.  Your suits are able to withstand the lethal dose of radiation, but\n";
    cout << "\tyour ship's computers are not.\n\n";

    // Player input loop
    do
    {
        cout << "\tTemporarily shutdown computer systems to save as much of the ship's computers as possible?\n";
        cout << "\tPress 1 to shutdown ship's computers.\n";
        cout << "\tPress 2 to leave computers running.\n\n";
        cin >> playerAction;

        // Decision results
        if (playerAction == 1)
        {
            cout << "\tAs the computers power down, the main lights turn off, and emergency lights start up.\n";
            cout << "\tThe solar flare subsides, leaving you and your crew with a dead ship.  Though inertia\n";
            cout << "\twill keep the ship moving for a little while, your crew has just a few hours to get the\n";
            cout << "\tships computers back online before the mission window closes.\n\n";
            break;
        }
        else {
            // Create random number between 1 - 10
            int gamble = rand() % 10 + 1;

            // 30% change of success
            if (gamble >= 7)
            {
                cout << "\tUnfortunately your gamble didn't work and your computer systems are to damaged to continue.\n";
                cout << "\tGAME OVER";
                exit(0);
            }
            else {
                cout << "\tThat was a bold move.  Fortunately the solar flare did minimal damage to your computer systems.\n\n";
                break;
            }
            break;
        }
    } while (playerAction > 0 && playerAction <= 2);

    return;
}

void missionArrival() {
    // Converting int value to string
    string travelTime = to_string(myMission.travelTime);
    cout << "\tAfter a long " + travelTime + " you have finally arrived at " + myMission.location + ".\n";
    
    return;
}

int main()
{    
    // Call startGame function
    startGame();
    
    // Chapter 2
    ch2Repair();
    
    // Action to be done for chapter 2's interactivity
    ch3Solar();

    // Calling last story function
    missionArrival();

    return 0;
}