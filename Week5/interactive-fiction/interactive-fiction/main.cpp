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
#include "functions.h"

// Namespaces to be used
using namespace std;

int main()
{    
    // Change console appearance to look like an old IBM terminal
    system("color 02");
    
    // Class variable
    Mission myMission;
    // Integer Variable
    int playerAction;

    // Assigning main function variables to class member variables
    string location = myMission.getLocation();
    int travelTime = myMission.getTravelTime();

    // Call startGame function
    startGame(location, travelTime, playerAction);

    // Reset variables to match new class member variables values
    // to be used by preceding functions
    myMission.setLocation(location);
    myMission.setTravelTime(travelTime);
    
    // Chapter 2
    ch2Repair(location, playerAction);
    
    // Chapter 3
    ch3Solar(location, playerAction);

    // Calling last story function
    missionArrival(location, travelTime);

    return 0;
}