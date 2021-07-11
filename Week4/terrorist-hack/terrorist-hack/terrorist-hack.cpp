#include <iostream>
#include <stdlib.h>

using namespace std;

// Prototype functions
double failedHack(double x, double y);
double successHack(double& x, double& y);

int main()
{
    // Old terminal look
    system("color 02");
    
    // Terrorist bank account
    double terroristBalance = 550000.75;
    // Joe's Coffee Shop bank account
    double shopBalance = 150.60;

    // Print bank account information from both accounts
    cout << "\tTerrorist account balance is : $" << terroristBalance << "\n";
    cout << "\tJoe\'s Coffee Shop account balance is: $" << shopBalance << "\n\n";

    // Bad swap account balances
        // Pass account info to function
    failedHack(terroristBalance, shopBalance);

    // Print unchanged account balance
    cout << "\tHACK FAILED!!!\n";
    cout << "\tTerrorist account balance is : $" << terroristBalance << "\n";
    cout << "\tJoe\'s Coffee Shop account balance is: $" << shopBalance << "\n\n";

    // Good swap account balances
        // Pass account references to function
    successHack(terroristBalance, shopBalance);

    // Print swapped balances
    cout << "\tHack successful...\n";
    cout << "\tTerrorist account balance is : $" << terroristBalance << "\n";
    cout << "\tJoe\'s Coffee Shop account balance is: $" << shopBalance << "\n\n";

    return 0;
}

double failedHack(double x, double y) {
    // Temp variable to hold x
    double temp = x;
    // x becomes the value of y
    x = y;
    // y becomes the value of temp
    y = temp;

    return x, y;
}

double successHack(double& x, double& y) {
    // Temp variable to hold x
    double temp = x;
    // x becomes the value of y
    x = y;
    // y becomes the value of temp
    y = temp;

    return x, y;
}