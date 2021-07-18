/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

#include <iostream>
#include <string>
#include "functions.h"
#include "blackjack.h"

using namespace std;

// Member function to set member variable location
void Mission::setLocation(string& location)
{
    // Member variable set to reference variable received from start-game function
    m_location = location;
}

// Member function to get location
string Mission::getLocation() const
{
    // Giving read-only access to member variable
    return m_location;
}

// Member function to set member variable travelTime
void Mission::setTravelTime(int& travelTime)
{
    // Member variable set to reference variable received from start-game function
    m_travelTime = travelTime;
}

// Member function to get member variable travelTime
int Mission::getTravelTime() const
{
    // Giving read-only access to member variable
    return m_travelTime;
}

void startGame(string& location, int& travelTime, int& playerAction)
{
    // Player input loop
    do
    {
        // Expected output for "Game Menu"
        cout << "\tPlease type in your mission location:\n\n";
        cout << "\tPress 1 for Mercury\n";
        cout << "\tPress 2 for Venus\n";
        cout << "\tPress 3 for The Moon\n";
        cout << "\tPress 4 for Mars\n\n";
        // Player input for mission seletion
        cin >> playerAction;
    } while (playerAction > 4 && playerAction < 1);

    // Assigning variables based on player input
    switch (playerAction)
    {
    case 1:
        location = "Mercury";
        travelTime = 1260;
        break;
    case 2:
        location = "Venus";
        travelTime = 109;
        break;
    case 3:
        location = "The Moon";
        travelTime = 3;
        break;
    case 4:
        location = "Mars";
        travelTime = 225;
        break;
    default:
        break;
    }

    // Mission selection dialog
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
    cout << "\tGood luck on your way to " + location + ", you hear of the radio.\n\n";

    return;
}

int ch2Repair(string location, int& playerAction)
{
    system("cls");
    
    // New level intro dialog with concantenated variables
    cout << "\tAfter a very exhilerating launch into space, you are on your way to " + location + "\n\n";
    cout << "\tWhile in your travels to " + location + ", the ship is straifed by a cloud debree of meteroids.\n";
    cout << "\tThese little micro-meteroids start leaving pin holes into the hull of your ship and a\n";
    cout << "\tpuncturing holes in various sections of your ship.\n\n";

    // Player input loop
    do
    {
        // Player interaction dialog
        cout << "\tWhat do you choose to repair first?\n";
        cout << "\tPress 1 to repair your fuel line.\n";
        cout << "\tPress 2 to repair your hull.\n";
        cout << "\tPress 3 to don your spacesuit.\n";
        cout << "\tPress 4 to repair your communications link.\n\n";
        // Player input for level 2 action
        cin >> playerAction;

        // Decision results
        if (playerAction != 3)
        {
            // Game over dialog
            cout << "\tThe oxygen was sucked out into space, causing you to decompress.\n\tGuess your crewmates will just have to continue on without you.\n";
            cout << "\tGAME OVER\n";
            exit(0);
        }
        else {
            // Continue mission dialog
            cout << "\tPutting on your spacesuit kept you from decompressing as the oxygen was sucked out of the hull.\n";
            break;
        }
    } while (playerAction > 0 && playerAction <= 4);

    return playerAction;
}

void ch3Solar(string location, int& playerAction)
{
    system("cls");

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

void missionArrival(string location, int travelTime) {
    system("cls");

    char answer;
    cout << "It's been a long time since anyone on your crew has relaxed.\n";
    cout << "Would you like to play a game? [Y]es or [N]o: ";
    cin >> answer;

    while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');
    {
        cout << "Please enter a valid response of [Y]es or [N]o.";
    }

    if (answer == 'y' || answer == 'Y')
    {
        system("cls");
        blackjack();
    }

    system("cls");

    // Converting int value to string
    string travelTimeStr = to_string(travelTime);

    // Outro dialog for game end
    cout << "\tAfter a long " + travelTimeStr + " you have finally arrived at " + location + ".\n";

    return;
}