#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    
    return rankString(myRank)+suitString(mySuit);

}

string Card::rankString(int r) const {
    string rankStr;
    switch(r){
        case 1:
            rankStr = 'A';
            break;
        case 11:
            rankStr = 'J';
            break;
        case 12:
            rankStr = 'Q';
            break;
        case 13:
            rankStr = 'K';
            break;
        default:
            rankStr = to_string(r);
    }

}

string Card::suitString(Suit s) const{

    string suitStr;

    switch(s){
        case hearts:
            suitStr = 'h';
            break;
        case diamonds:
            suitStr = 'd';
            break;
        case clubs:
            suitStr = 'c';
            break;
        default:
            suitStr = 's';
    }
    return (suitStr);
}

int Card::getRank() const {
    return myRank;
}

bool Card::sameSuitAs(const Card& c) const {
    return (mySuit == c.mySuit);
}

bool Card::operator == (const Card& rhs) const {
    return(myRank == rhs.myRank && mySuit == rhs.mySuit );
}

bool Card::operator != (const Card& rhs) const{
    return(mySuit != rhs.mySuit || myRank != rhs.myRank);
}