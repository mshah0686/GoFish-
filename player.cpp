//
// Created by Malav Shah on 2019-04-09.
//

#include "player.h"
using namespace std;
Player::Player() {
    myName = "Kenneth";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
    incrementIndexCard();
}

void Player::incrementIndexCard() {
    indexCard = myHand[(findCardInHand(indexCard) + 1) % myHand.size()];
}

void Player::bookCards(Card c1, Card c2) {
    //cout << "In book..." << endl;
    //cout << "c1: " << c1.toString() << " c2: " << c2.toString() << endl;
    myBook.push_back(c1);
    myBook.push_back(c2);
}


bool Player::checkHandForPair(Card &c1, Card &c2) {
    for(int i = 0; i < myHand.size(); i++) {
        for(int j = i + 1; j < myHand.size(); j++) {
            if(myHand[i].getRank() == myHand[j].getRank()) {
                c1 = myHand[i];
                c2 = myHand[j];
                cout << myHand[i].toString() << " == " << myHand[j].toString() << endl;
                return true;
            }else{
                cout << myHand[i].toString() << " != " << myHand[j].toString() << endl;
            }
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    for(vector<Card>::iterator i = myHand.begin(); i != myHand.end(); i++) {
        if(*i == c) {
            myHand.erase(i);
            if(c == indexCard){
                incrementIndexCard();
            }
            return c;
        }
    }
    return c;
}

Card Player::removeCardWithSameRankFromHand(Card c) {
    for(vector<Card>::iterator i = myHand.begin(); i != myHand.end(); i++) {
        if(i->getRank() == c.getRank()) {
            myHand.erase(i);
            return c;
        }
    }
    cout << "Major ERROR in removeCardWithSameRankFromHand()" << endl;
    exit(-1);
    return c;
}

bool Player::cardInHand(Card c) const {
    for(Card card : myHand) {
        if(card == c) {
            return true;
        }
    }
    return false;
}

void Player::initPlayerAI() {
    indexCard = myHand[0];
}

Card Player::chooseCardFromHand() {
    //find index of indexCard
    int index = findCardInHand(indexCard);
    Card cpy = indexCard;
    incrementIndexCard();
    return cpy;
}

int Player::findCardInHand(Card c) const{
    int i=0;
    for(i=0; i < myHand.size(); i++){
        if(myHand[i] == c){
            return i;
        }
    }
    return -1;
}
bool Player::sameRankInHand(Card c) const {
    for(Card card : myHand) {
        if(card.getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

string Player::showHand() const {
    string ret;
    for(Card card : myHand) {
        ret += card.toString() + " ";
    }
    return ret;
}

string Player::showBooks() const {
    string ret;
    if (myBook.size() >= 2) {
        for (int i = 0; i < myBook.size() - 1; i+=2) {
            ret += " Pair: " + myBook[i].toString() + " " + myBook[i + 1].toString();
        }
    }
    return ret;
}

int Player::getBookSize() const {
    return myBook.size() / 2;
}

int Player::getHandSize() const {
    return myHand.size();
}
void Player::findPairsBookCards() {
    Card c1;
    Card c2;
    cout << "booking for " << getName() << endl;
    cout << "hand before " << showHand() << endl;
    cout << "book before " << showBooks() << endl;
    while (checkHandForPair(c1,c2)){

        cout << "booking..." << endl;
        bookCards(c1, c2);
        cout << "book after " << showBooks() << endl;
        removeCardFromHand(c1); //TODO fails here check modulo in incIndexCard
        cout << "here" << endl;
        removeCardFromHand(c2); // TODO <------
        cout << "hand after " << showHand() << endl;

    }
}
