#include <iostream>

using namespace std;

int main()
{
    // Try is used to test a block of code for exception handling
    try {
        int age;

        cout << "Please enter your age.\n";
        cin >> age;

        if (age >= 18) {
            cout << "Access granted - you are old enough.";
        }
        else {
            // Throw is used when tested code does not meet parameters, creating a "custom" error
            throw (age);
        }
    }
    
    // Catch captures "custom" error and provides program with an out if "custom" error occurs
    catch (int myNum) {
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Age is: " << myNum;
    }
}