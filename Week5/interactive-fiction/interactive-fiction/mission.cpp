/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

#include <iostream>
#include <string>
#include "mission.h"

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
