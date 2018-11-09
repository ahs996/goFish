// FILE: player.cpp
//  * Name: Anna Sim
//  * email address: ahs996@utexas.edu
//  * UTEID: ahs996
//  * Section 5 digit ID: 16185
#include "player.h"

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
        for(int j=i + 1; j<myHand.size(); j++) {
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
    for (int i=0; i<myHand.size(); i++) {
        if (c == myHand.at(i)){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    vector<Card>::iterator it;
    for(it = myHand.begin(); it != myHand.end(); it++) {
        if (*it == c) {
            myHand.erase(it);
            return c;
        }
    }
    return c;
}

string Player::showHand() const {
    string handd;
    for(int i=0; i<myHand.size(); i++) {
        handd += myHand.at(i).toString() + ", ";
    }
    return handd;
}

string Player::showBooks() const {
    string str;
    for(int i=0; i<myBook.size(); i++) {
        str += myBook.at(i).toString() + ", ";
    }
    return str;
}

int Player::getHandSize() const{
    return myHand.size();
}
int Player::getBookSize() const{
    return myBook.size();
}

bool Player::rankInHand(Card c) const {
    for (int i=0; i<myHand.size(); i++) {
        if (c.getRank() == myHand.at(i).getRank()){
            return true;
        }
    }
    return false;
}