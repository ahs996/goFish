// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
//  * Name: Anna Sim
//  * email address: ahs996@utexas.edu
//  * UTEID: ahs996
//  * Section 5 digit ID: 16185

// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck
{
  static const int SIZE = 52;
  
  public:
    
    /* FUNCTION - deck
    * sets sorted deck

    precondition: not empty

    input parms : none

    output parms :
    */
    Deck();           // pristine, sorted deck

    /* FUNCTION - shuffle
    * shuffles deck

    precondition: not empty

    input parms : none

    output parms :
    */
    void shuffle();   // shuffle the deck, all 52 cards present
    
    /* FUNCTION - dealCard
    * get a card
    *   stop after 52 cards are dealt

    precondition: not empty

    input parms : none

    output parms :
    */
    Card dealCard();   // get a card, after 52 are dealt, fail 

    /* FUNCTION - int size
    *returns  number of cards left in the deck

    precondition: not empty

    input parms : none

    output parms : size of deck
    */
    int  size() const; // # cards left in the deck

  private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif