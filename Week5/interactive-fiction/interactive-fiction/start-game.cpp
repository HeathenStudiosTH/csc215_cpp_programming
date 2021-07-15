/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

#include <iostream>
#include "mission.h"
#include "start-game.h"

using namespace std;

// Function to start the game
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
