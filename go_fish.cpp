// FILE: go_fish.cpp

//  * Name: Anna Sim
//  * email address: ahs996@utexas.edu
//  * UTEID: ahs996
//  * Section 5 digit ID: 16185
//  
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides fs and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void playerGame(Player &p1, Player &p2, Deck &d);
ofstream fs;

int main( )
{
    fs.open ("goFishResults.txt");

    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    bool p1Turn;
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    fs << p1.getName() <<" has : " << p1.showHand() << endl;
    fs << p2.getName() <<" has : " << p2.showHand() << endl;
    fs << endl;
    
    p1Turn = true; //a flag to switch the players turn

    while(p1.getBookSize() + p2.getBookSize() < 52){

        if(p1Turn){
           playerGame(p1, p2, d);
           p1Turn = false;
       }
       else{
           playerGame(p2, p1, d);
           p1Turn = true;
       }
    }
    
    // game ends once a book has all pairs

    if (p1.getBookSize() < p2.getBookSize()){
        fs << p1.getName() << " wins" << endl;
    }
    
    if (p1.getBookSize() == p2.getBookSize()){
        fs << "It's a tie!" << endl;
    }

    else {
        fs << p2.getName() << " wins" << endl;
    }
    
    fs.close(); //close file

    return EXIT_SUCCESS;  
}

void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

void playerGame(Player &p1, Player &p2, Deck &d){
    Card pCard;
    Card pCard2;
    Card drawCard;

    bool pTurn = true;

    while(pTurn){
        while (p1.checkHandForBook(pCard, pCard2)) {
            // check for existing pairs in the hand then add to book
            p1.bookCards(pCard, pCard2);
        }


        if(p1.getHandSize() == 0) {
            // break if handsize is 0
            break;
        }
        
        pCard = p1.chooseCardFromHand();
        // fs <<  << endl;
        
        fs << p1.getName() << " asks - Do you have a " <<  pCard.rankString(pCard.getRank())+"?" << endl;
        if (p2.rankInHand(pCard)) {
            // if p2 has the card p1 asks for, do:
            fs << p2.getName() << " says - Yes I have a " << pCard.rankString(pCard.getRank())+"."  << endl;
            pCard2 = p2.removeCardFromHand(pCard);
            p1.addCard(pCard2);
            p1.bookCards(pCard, pCard2);
            fs << p1.getName()+ " books the "+pCard.rankString(pCard.getRank()) << endl;
            pTurn = true;
        }
        else {
            fs << p2.getName() << " says - Go Fish" << endl;
            pTurn = false;
        }

    }
    // while the deck is not empty, draw a card
    // draw a card when the other player says Go Fish or handsize is 0
    if(d.size() != 0) {
        drawCard = d.dealCard();
        p1.addCard(drawCard);
        fs << p1.getName()+ " draws the " + drawCard.toString() << endl;
    }

    fs << "*********************************************************" << endl;
    pTurn = false;
}


