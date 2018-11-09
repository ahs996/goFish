// FILE:deck.cpp
//  * Name: Anna Sim
//  * email address: ahs996@utexas.edu
//  * UTEID: ahs996
//  * Section 5 digit ID: 16185
#include "deck.h"

Deck::Deck() {
    for(int i=0; i<4; i++){
        Card::Suit s;
        switch(i){
            case 1:
                s = Card::hearts;
                break;
            case 2:
                s = Card::diamonds;
                break;
            case 3:
                s = Card::clubs;
                break;
            default:
                s = Card::spades;
        }
        for(int j=1; j<14; j++){
            Card c(j, s);
            myCards[i*13+j-1] = c;    
        }
    }
    myIndex = 0;
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime); 
}

void Deck::shuffle(){
    if (size() < 2 ){
        return;
    }

    int randomI = (rand() % size());
    int randomI2 = (rand() % size());
    Card temp;
    for(int i=0; i<1000; i++){
        temp = myCards[randomI];
        myCards[randomI] = myCards[randomI2];
        myCards[randomI2] = temp;
    }
}
// precondition: The deck is never empty
Card Deck::dealCard(){
    return myCards[myIndex++];
}

int Deck::size() const {
    return (SIZE - myIndex);
}
