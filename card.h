//File Name: card.h
//
// Name: Anna Sim
// EID: AHS996
// Unique: 16185

//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
  public:

    enum Suit {spades, hearts, diamonds, clubs};

    /* FUNCTION - Card()
      * Sets default card to ace of spades
      precondition: ace of spades

      input parms : none

      output parms : none
    */
    Card();    
    
    /* FUNCTION - Card(int rank, Suit s)
      * sets rank and suit of a card

      precondition: Valid rank and suit

      input parms : int rank, Suit s

      output parms : none
    */
    Card(int rank, Suit s);
    
    /* FUNCTION - string toString
      *converts rank and suit of a card to a string
      precondition: are valid rank and suit

      input parms :

      output parms : string concatenation of rank and suit
    */
    string toString()              const;  // return string version e.g. Ac 4h Js
    
    /* FUNCTION - bool sameSuitAs
    * attempts to add a new song to the UtPod
        o returns true if suit is same as c
        o otherwise false

    precondition: not a null card

    input parms : Card& c

    output parms : true, false
    */
    bool sameSuitAs(const Card& c) const;  

    /* FUNCTION - int getRank
      *gets rank of a card
          o returns rank from 1-13

      precondition: 

      input parms : 

      output parms : myRank
    */    
    int  getRank()                 const; 
    
    /* FUNCTION - string suitString
      * attempts to add a new song to the UtPod
          o return "s", "h",...

      precondition: s is a valid Song

      input parms : Suit s

      output parms : "s", "h",...
    */
    string suitString(Suit s)      const;  // 
    
    /* FUNCTION - string rankString
      * converts rank to a string
          o returns a 2-10 or
          o A, J, Q, K

      precondition: r is in range 1-13

      input parms : int r

      output parms : string of r
    */    
    string rankString(int r)       const; 
    
    
    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;
    

    
  private:

    int myRank;
    Suit mySuit;

    
};

ostream& operator << (ostream& out, const Card& c);



#endif