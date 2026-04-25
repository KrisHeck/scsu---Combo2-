#include "CPlayer.h"
#include <stdio.h>

CPlayer::CPlayer(const char* n) : name(n) {}
const char* CPlayer::getName() const { return name; }
int CPlayer::handSize() const { return static_cast<int>(hand.size()); }
void CPlayer::addToHand(const Domino& d) { hand.push_back(d); }

Domino CPlayer::removeAt(int idx) {
    Domino d = hand[idx];
    hand.erase(hand.begin() + idx);
    return d;
}

const std::vector<Domino>& CPlayer::getHand() const { return hand; }

void CPlayer::printHand() const {
    printf("%s hand(%d): ", name, handSize());
    for (size_t i = 0; i < hand.size(); ++i) {
        hand[i].print();
        printf(" ");
    }
    printf("\n");
}

CPlayer::PlayChoice CPlayer::findMatch(int headValue, int tailValue) const {
    for (int i = 0; i < static_cast<int>(hand.size()); ++i) {
        Domino d = hand[i];

        if (d.right == headValue) return PlayChoice(true, i, false, 0);
        if (d.left == headValue)  return PlayChoice(true, i, true, 0);
        if (d.left == tailValue)  return PlayChoice(true, i, false, 1);
        if (d.right == tailValue) return PlayChoice(true, i, true, 1);
    }
    return PlayChoice();
}
