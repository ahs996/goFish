// FILE: player.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include "player.h"

using namespace std;

void Player::addCard(Card c) {
    myHand.push_back(c); //add to vector
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){
    for(int i=0; i<myHand.size(); i++){
        for(int j=i; i<myHand.size(); j++) {
            if (myHand.at(i).getRank() == myHand.at(j).getRank()) {
                c1 = myHand.at(i);
                c2 = myHand.at(j);
                return true;
            }
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    int randomInt = (rand() % myHand.size());
    return myHand.at(randomInt);
}

bool Player::cardInHand(Card c) const {
    for (Card card : myHand) {
        if (c == card){
            return true;
        }
        else {
            return false;
        }
    }
}

Card Player::removeCardFromHand(Card c) {
    vector<Card>::iterator it;
    for(it = myHand.begin(); it != myHand.end(); it++) {
        if (*it == c) {
            myHand.erase(it);
            return c;
        }
    }
}

string Player::showHand() const {
    string str;
    for(Card card : myHand) {
        str += card.toString() + ", ";
    }
    return str;
}

string Player::showBooks() const {
    string str;
    for(Card card : myBook) {
        str += card.toString() + ", ";
    }
    return str;
}

int Player::getHandSize() const{
    return myHand.size();
}
int Player::getBookSize() const{
    return myBook.size();
}