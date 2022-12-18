// Interface of Game class

#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Player.h"
#include "Deck.h"

class Game {
public:
    explicit Game(); // constructor
    void newGame(); // plays through one round of blackjack and displays winner
    int playGame(); // determines winner of one round of blackjack - returns 0 for tie, 1 for human win, 2 for dealer win
    bool checkForQuit(); // asks user whether he wants to quit - returns true for quit, false for continue

private:
    Deck deck;
    Human human;
    Dealer dealer;
};

#endif // GAME_H
