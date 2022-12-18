// Implementation of Player class and Human and Dealer subclasses

#include "Player.h"

// Performs actions for player's turn - to be implemented by child classes
void Player::turn(Deck& deck) {};

// Empties player's hand
void Player::clearHand() {
    cards = {};
}

// Adds a given card to the player's hand
void Player::drawCard(Deck::PlayingCard newCard) {
    cards.push_back(newCard);
}

// Calculates the value of a player's hand
int Player::handValue() {
    int aces = 0; // number of aces encountered, to help deal with ace being worth either 1 or 11
    int total = 0;

    for (Deck::PlayingCard& i: cards) { // go through all the cards in the hand
        if (i.face == Deck::ACE) { // ace
            total += 11; // count it as 11
            aces += 1; // if we go over 21, we can count it as 1 later
        }
        else if (i.face > Deck::TEN) // face card
            total += 10;
        else // number card
            total += i.face;
    }

    // deal with the aces
    // repeatedly subtract 10 until either we are at 21 or below, or we have no more aces
    while ((total > 21) && (aces > 0)) {
        total -= 10;
        aces -= 1;
    }

    return total;
}

// Displays graphically the player's hand
void Player::displayHand() {

    static std::string face_art[14] = {"  ", "A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K "};
    static std::string suit_art[4][3] = { {" () ",   "()()",  " /\\ "},   // clubs symbol
                                          {"/\\/\\", "\\  /", " \\/ "},   // hearts symbol
                                          {" /\\ ",  "(  )",  " /\\ "},   // spades symbol
                                          {" /\\ ",  "(  )",  " \\/ "} }; // diamonds symbol

    std::cout << std::endl;

    // row 1 of picture
    for (Deck::PlayingCard& i: cards)
        std::cout << " ____  ";
    std::cout << std::endl;

    // row 2 of picture
    for (Deck::PlayingCard& i: cards)
        std::cout << "|" << face_art[i.face] << "  | ";
    std::cout << std::endl;

    // row 3 of picture
    for (Deck::PlayingCard& i: cards)
        std::cout << "|" << suit_art[i.suit][0] << "| ";
    std::cout << std::endl;

    // row 4 of picture
    for (Deck::PlayingCard& i: cards)
        std::cout << "|" << suit_art[i.suit][1] << "| ";
    std::cout << std::endl;

    // row 5 of picture
    for (Deck::PlayingCard& i: cards)
        std::cout << "|" << suit_art[i.suit][2] << "| ";
    std::cout << std::endl;

    // row 6 of picture
    for (Deck::PlayingCard& i: cards)
        std::cout << "|____| ";
    std::cout << std::endl;
}


// Performs actions for human's turn
void Human::turn(Deck& deck) {
    while (true) { // player can keep hitting as long as he wants
        char inp; // store user's choice

        std::cout << "\nYour hand is: ";
        displayHand();

        std::cout << "Do you want to hit or stand? Type 'h' or 's': ";
        while (true) { // keep trying until we get a valid input
            std::cin >> inp;
            if (inp == 's' || inp == 'S') // stand
                return; // turn is over
            else if (inp == 'h' || inp == 'H') { // hit
                drawCard(deck.selectCard()); // draw a card
                break;
            }
            else
                std::cout << "Invalid input. Try again: ";
        }

        if (handValue() > 21) { // if the player busts, the turn is over
            std::cout << "\nYour hand is: ";
            displayHand();
            std::cout << "Bust! Turn over." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2)); // wait for 2 seconds so the user can see the message
            return;
        }
    }
}


// Performs actions for dealer's turn
void Dealer::turn(Deck& deck) {
    while (handValue() < 17) // if less than 17, hit; otherwise stand
        drawCard(deck.selectCard()); // draw a card
}
