#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "blackjack.h"
#include "banner.h"
#include "source.h"

using namespace std;

//function prototypes
ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const Person& aPerson);

void blackjack()
{
    // Change console appearance
    system("color 02");

    // Call Banner function
    banner();

    // No. of Players variable
    int numPlayers = 0;
    // Loop to determine how many players are playing
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    // String vector to store names of players
    vector<string> names;
    string name;
    // Loop to establish name value to each player
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    // The game loop        
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return;
}

//overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    // If card is face up, display values
    if (aCard.m_IsFaceUp)
    {
        // Template to display card value
        os << "[" << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit] << "]";
    }
    else
    {
        // Template display for face down card
        os << "[XX]";
    }

    return os;
}

//overloads << operator so a GenericPlayer object can be sent to cout
ostream& operator<<(ostream& os, const Person& aPerson)
{
    // Display players name
    os << aPerson.m_Name << ":\t";

    // Card object vector to store card values
    vector<Card*>::const_iterator pCard;
    // If person's hand is not empty
    if (!aPerson.m_Cards.empty())
    {
        // Cycle through each card in person's hand
        for (pCard = aPerson.m_Cards.begin(); pCard != aPerson.m_Cards.end(); ++pCard)
        {
            // Template display for each card value revealing rank, then suit
            os << *(*pCard) << "\t";
        }


        // If person's hand doesn't equal 0
        if (aPerson.GetTotal() != 0)
        {
            // Reveal person's total
            cout << "(" << aPerson.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}