#include <iostream>

#include "Game.h"

int main() {
    Game game = Game(); // create a new Game object

    // display header
    std::cout << std::endl << "----------" << std::endl;
    std::cout << std::endl << "Blackjack Game";
    std::cout << std::endl << "version 1.1";
    std::cout << std::endl << "(c) 2018 Kevin Roche" << std::endl;

    do game.newGame(); // play the game
    while (!game.checkForQuit()); // until the user quits

    return 0;
}
