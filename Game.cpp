// Implementation of Game class

#include "Game.h"

// Constructor
Game::Game() {
    // initialize deck and players
    deck = Deck();
    human = Human();
    dealer = Dealer();
}

// Plays through one round of blackjack and displays winner
void Game::newGame() {
    // delegate to playGame, which plays a round and determines the winner
    int winner = playGame();

    // display the players' hands and scores
    std::cout << "\n----------\n";

    std::cout << "\nYour hand: " << human.handValue();
    human.displayHand();

    std::cout << "\nDealer's hand: " << dealer.handValue();
    dealer.displayHand();

    std::cout << "\n";

    switch(winner) { // use returned value from playGame()
        case 0: std::cout << "Tie!" << std::endl; break;
        case 1: std::cout << "You win!" << std::endl; break;
        case 2: std::cout << "Dealer wins!" << std::endl; break;
    }
}

// Determines winner of one round of blackjack
// Returns 0 for tie, 1 for human win, 2 for dealer win
int Game::playGame() {
    // empty players' hands
    human.clearHand();
    dealer.clearHand();

    deck.shuffleDeck(); // shuffle the deck

    // display message
    std::cout << "\n----------\n";
    std::cout << "\nNew game!" << std::endl;

    // deal each player 2 cards
    human.drawCard(deck.selectCard());
    dealer.drawCard(deck.selectCard());
    human.drawCard(deck.selectCard());
    dealer.drawCard(deck.selectCard());

    // check to see if anyone wins after initial deal
    if ((human.handValue() == 21) && (dealer.handValue() == 21)) // both have 21, tie
        return 0;
    else if (human.handValue() == 21) // human has 21, human wins
        return 1;
    else if (dealer.handValue() == 21) // dealer has 21, dealer wins
        return 2;

    // each player takes his turn
    human.turn(deck);
    dealer.turn(deck);

    // determine the winner
    if (human.handValue() > 21) // if the human busts, the dealer wins
        return 2;
    else if (dealer.handValue() > 21) // if the dealer busts but not the human, the human wins
        return 1;
    else if (human.handValue() > dealer.handValue()) // if the human beats the dealer, the human wins
        return 1;
    else if (dealer.handValue() > human.handValue()) // if the dealer beats the human, the dealer wins
        return 2;
    else // otherwise it is a tie
        return 0;
}

// Asks user whether he wants to quit
// Returns true for quit, false for continue
bool Game::checkForQuit() {
    char inp;
    std::cout << "Do you want to play again? Type 'y' or 'n': ";

    while (true) { // keep trying until we get a valid input
        std::cin >> inp; // get user input
        if (inp == 'y' || inp == 'Y')
            return false; // don't want to quit
        else if (inp == 'n' || inp == 'N')
            return true; // do want to quit
        else
            std::cout << "Invalid input. Try again: ";
    }
}
