#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include "deck.h"

using namespace std;

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
}

void Deck::shuffle(){
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime); 
    Card temp;
    for(int i=0; i<1000; i++){
        int randomI = (rand() % size());
        int randomI2 = (rand() % size());
        temp = myCards[randomI];
        myCards[randomI] = myCards[randomI2];
        myCards[randomI2] = temp;
    }
}

Card Deck::dealCard(){
    if (myIndex == 52){
        return;
    }
    else {
        return myCards[myIndex++];
    }
}

int Deck::size() const {
    return (SIZE - myIndex);
}
