/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

#include <iostream>
#include <string>
#include "mission.h"
#include "final-level.h"

using namespace std;

void missionArrival(string location, int travelTime) {
    // Converting int value to string
    string travelTimeStr = to_string(travelTime);
    
    // Outro dialog for game end
    cout << "\tAfter a long " + travelTimeStr + " you have finally arrived at " + location + ".\n";

    return;
}