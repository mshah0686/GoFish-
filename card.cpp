#include "card.h"

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

string Card::rankString(int r) const {
    string rankString;
    switch (r) {
        case 1:
            rankString = "A";
            break;
        case 11:
            rankString = "J";
            break;
        case 12:
            rankString = "Q";
            break;
        case 13:
            rankString = "K";
            break;
        default:
            rankString = to_string(r);
            break;
    }
    return rankString;
}

string Card::suitString(Card::Suit s) const {
    string suitString;
    switch (s) {
        case spades:
            suitString = "s";
                    break;
        case clubs:
            suitString = "c";
            break;
        case diamonds:
            suitString = "d";
            break;
        case hearts:
            suitString = "h";
            break;
        default:
            cout << "ERROR" << endl;
            exit(-1);
    }

    return suitString;
}

bool Card::operator==(const Card &rhs) const {
    return (toString() == rhs.toString());
}

bool Card::operator!=(const Card &rhs) const {
    return !(*this == rhs);
}

int Card::getRank() const {
    return myRank;
}

bool Card::sameSuitAs(const Card &c) const {
    return mySuit == c.mySuit;
}

ostream& Card::operator<<(ostream &out) {
    out << this->toString() << endl;
    return out;
}