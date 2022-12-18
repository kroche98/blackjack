// Implementation of Deck class

#include "Deck.h"

// Constructor
Deck::Deck() {
    curSize = 52; // initialize the deck's size

    // put the cards into the deck in unshuffled order
    int nextSlot = 0;
    for (int i = CLUBS; i <= DIAMONDS; i++) {
        for (int j = ACE; j <= KING; j++) {
            order[nextSlot].suit = i;
            order[nextSlot].face = j;
            nextSlot++;
        }
    }
}

// Returns any cards taken out and shuffles the deck
void Deck::shuffleDeck() {
    curSize = 52; // restore deck to full size
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // obtain a seed using current time
    shuffle(order.begin(), order.end(), std::default_random_engine(seed)); // shuffle the deck randomly
}

// Removes and returns a card from the deck
Deck::PlayingCard Deck::selectCard() {
    curSize -= 1; // "remove" the card
    return order[curSize]; // return the top card of the deck
}
