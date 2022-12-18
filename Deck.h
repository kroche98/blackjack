// Interface of Deck class

#ifndef DECK_H
#define DECK_H

#include <array>
#include <string>
#include <algorithm> // std::shuffle
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock

class Deck {
public:
    // represents a single standard-deck playing card
    struct PlayingCard {
        short face;
        short suit;
    };

    // enums for faces and suits
    // note that TWO = 2, THREE = 3, etc.
    enum faces {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum suits {CLUBS=0, HEARTS, SPADES, DIAMONDS};

    explicit Deck(); // constructor
    void shuffleDeck(); // returns any cards taken out and shuffles the deck
    PlayingCard selectCard(); // removes and returns a card from the deck

private:
    int curSize; // current number of cards in the deck
    std::array<PlayingCard, 52> order; // stores the order of cards in deck
};

#endif // DECK_H
