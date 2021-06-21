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

int main()
{
    // Variables for mission selection and mission locations
    int levelSelect;
    string location;
    int travelTime;
    
    // Variables to grab key value and turn it from char to int
    char keyPress;
    int asciiValue;

    // Variable to keep action entry from user
    int action;

    do
    {
        cout << "\tPlease type in your mission location:\n\n";
        cout << "\tPress 1 for Mercury\n";
        cout << "\tPress 2 for Venus\n";
        cout << "\tPress 3 for The Moon\n";
        cout << "\tPress 4 for Mars\n\n";
        cin >> levelSelect;
    } while (levelSelect < 1 || levelSelect > 4);

    switch (levelSelect)
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

    // Simple text for story
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
    cout << "\tGood luck on your way to " + location + ", you hear of the radio.\n" << endl;

    // Quick break to continue story to next "chapter".
    do
    {
        cout << "\tPress the Space key to continue: \n\n";
        keyPress = _getch();
        asciiValue = keyPress;
        
        // Checking if the spacebar ascii value (32) was pressed
        if (asciiValue == 32)
        {
            break;
        }
    } while (1);

    // Chapter 2
    cout << "\tWhile in your travels to " + location + ", the ship is straifed by a cloud debree of meteroids.\n";
    cout << "\tThese little micro-meteroids start leaving pin holes into the hull of your ship and a\n\tpuncturing holes in various sections of your ship.\n\n";

    // Action to be done for chapter 2's interactivity
    do
    {
        cout << "\tWhat do you choose to repair first?\n";
        cout << "\tPress 1 to repair your fuel line.\n";
        cout << "\tPress 2 to repair your hull.\n";
        cout << "\tPress 3 to don your spacesuit.\n";
        cout << "\tPress 4 to repair your communications link.\n\n";
        cin >> action;

        if (action != 3)
        {
            cout << "\tThe oxygen was sucked out into space, causing you to decompress.\n\tGuess your crewmates will just have to continue on without you.\n";
            cout << "\tGame Over\n";
            exit(0);
        }
        else {
            cout << "\tPutting on your spacesuit kept you from decompressing as the oxygen was sucked out of the hull.\n";
            break;
        }
    } while (action > 0 && action <= 4);

    cout << "\tThe rest of the crew attend to the damage while you check mission heading.\n";
    cout << "\tThe ships computer reveals you're still heading for " + location + ".\n\n";

    action = 0;
    do
    {
        cout << "\tDo you still wish to head to " + location + "?\n";
        cout << "\tPress 1 for continue\n";
        cout << "\tPress 2 to abort\n\n";
        cin >> action;

        if (action == 2)
        {
            cout << "\tReturn to Earth in disgrace.\n";
            exit(0);
        }
        else {
            cout << "\tContinuing mission to " + location + ".\n\n";
            break;
        }
    } while (action > 0 && action <= 2);

    string travelStr = to_string(travelTime);
    cout << "\tAfter a long " + travelStr + " days in space, you've arrived at " + location + ".\n";

    return 0;
}