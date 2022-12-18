// Interface of Player class and Human and Dealer subclasses

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include <thread> // sleep_for
#include <chrono> // std::chrono::seconds

#include "Deck.h"

class Player {
public:
    void turn(Deck& deck); // perform actions for player's turn
    void clearHand(); // empties player's hand
    void drawCard(Deck::PlayingCard newCard); // adds a given card to the player's hand
    int handValue(); // calculates the value of a player's hand
    void displayHand(); // displays graphically the player's hand

protected:
    std::vector<Deck::PlayingCard> cards; // what cards the player has in his hand
};

class Human: public Player {
public:
    void turn(Deck& deck); // performs actions for human's turn
};

class Dealer: public Player {
public:
    void turn(Deck& deck); // performs actions for dealer's turn
};

#endif // PLAYER_H
