/***************************************|
|   Interactive Fiction Project         |
|   Timothy Hebert                      |
|   CSC215 - C++ Programming I          |
|   University of Advancing Technology  |
|***************************************/

#include <iostream>
#include <string>
#pragma once

using namespace std;

// Create Mission class to establish game elements
class Mission {
public:
    // Member functions for location
    void setLocation(string& location);
    string getLocation() const;

    // Member functions for travelTime
    void setTravelTime(int& travelTime);
    int getTravelTime() const;
private:
    string m_location;
    int m_travelTime;
};

void startGame(string& location, int& travelTime, int& playerAction);

int ch2Repair(string location, int& playerAction);

void ch3Solar(string location, int& playerAction);

void missionArrival(string location, int travelTime);