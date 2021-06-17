/*
	Game On Project
	Timothy Hebert
	CSC215 - C++ Programming I
	University of Advancing Technology
*/

// Links the input/output stream standard library
#include <iostream>
// Establishes connection with cout from standard library
using std::cout;
// Establishes connection with cin from standard library
using std::cin;
// Establishes connection with endl from standard library
using std::endl;

// Required funtion for file
int main() {
	// Establish randomNumber variable and empty variable for player input
	int guessNumber;

	// Establish random number to be guessed
	int randomNumber = rand() % 9 + 1;

	// Sending string with "end of line" to terminal via cout
	cout << "Game On!" << endl;
	cout << "Pick a number between 1-9." << endl;

	// Requiring user input
	cin >> guessNumber;

	// if suite to check if guess was correct
	if (guessNumber == randomNumber) {
		// Announcement for correct entry
		cout << "Congrats! You guessed correctly" << endl;
	}
	else {
		// Announcement for incorrect entry
		cout << "Oops.  That was incorrect" << endl;
	}

	// Returning a value of 0 for function to close
	return 0;
}