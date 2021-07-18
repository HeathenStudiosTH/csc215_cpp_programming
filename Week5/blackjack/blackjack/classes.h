#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#pragma once

using namespace std;

// Card Class
class Card
{
public:
    // Enumerators to hold rank and suit values
    enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    //overloading << operator so can send Card object to standard output 
    friend ostream& operator<<(ostream& os, const Card& aCard);

    // Card constructor
    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    // Returns the value of a card, 1 - 11
    int GetValue() const;

    // Flips a card
    void Flip();
private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

// Hand Class
class Hand
{
public:
    // Hand constructor
    Hand();
    // Hand destructor
    virtual ~Hand();
    // Adds a card to the hand
    void Add(Card* pCard);
    // Clears hand of all cards
    void Clear();
    // Gets hand total value
    int GetTotal() const;
protected:
    // Vector to hold individual card values
    vector<Card*> m_Cards;
};

// Person Class
class Person : public Hand
{
    friend ostream& operator<<(ostream& os, const Person& aGenericPlayer);
public:
    // Person constructor
    Person(const string& name = "");
    // Person destructor
    virtual ~Person();
    // Indicates whether or not person wants to keep hitting
    virtual bool IsHitting() const = 0;
    // Returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const;
    // Announces that the generic player busts
    void Bust() const;
protected:
    string m_Name;
};

// Player Class
class Player : public Person
{
public:
    // Player constructor
    Player(const string& name = "");
    // Player destructor
    virtual ~Player();
    // Returns whether or not the player wants another hit       
    virtual bool IsHitting() const;
    // Announces that the player wins
    void Win() const;
    // Aannounces that the player loses
    void Lose() const;
    // Announces that the player pushes
    void Push() const;
};

// Dealer Class
class Comp : public Person
{
public:
    // Computer constructor
    Comp(const string& name = "House");
    // Computer destructor
    virtual ~Comp();
    // Indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;
    // Flips over first card
    void FlipFirstCard();
};

// Deck Class
class Deck : public Hand
{
public:
    // Deck constructor
    Deck();
    // Deck destructor
    virtual ~Deck();
    // Create a standard deck of 52 cards
    void Populate();
    // Shuffle cards
    void Shuffle();
    // Deal one card to a hand
    void Deal(Hand& aHand);
    // Give additional cards to a generic player 
    void AdditionalCards(Person& aPerson);
};

// Game Class
class Game
{
public:
    // Game constructor
    Game(const vector<string>& names);
    // Game destructor
    ~Game();
    // Plays the game of blackjack    
    void Play();
private:
    Deck m_Deck;
    Comp m_Comp;
    vector<Player> m_Players;
};