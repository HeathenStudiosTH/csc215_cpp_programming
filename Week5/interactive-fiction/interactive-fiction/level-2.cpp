/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

#include <iostream>
#include <string>
#include "mission.h"
#include "level-2.h"

using namespace std;

int ch2Repair(string location, int& playerAction)
{
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