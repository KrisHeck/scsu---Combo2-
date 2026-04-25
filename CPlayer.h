#pragma once

#include "Domino.h"
#include <vector>

class CPlayer {
private:
    const char* name;
    std::vector<Domino> hand;

public:
    explicit CPlayer(const char* n);

    const char* getName() const;
    int handSize() const;
    void addToHand(const Domino& d);
    Domino removeAt(int idx);
    const std::vector<Domino>& getHand() const;
    void printHand() const;

    struct PlayChoice {
        bool found;
        int idx;
        bool flip;
        int placeEnd;
        PlayChoice() : found(false), idx(-1), flip(false), placeEnd(1) {}
        PlayChoice(bool f, int i, bool fl, int e) : found(f), idx(i), flip(fl), placeEnd(e) {}
    };

    PlayChoice findMatch(int headValue, int tailValue) const;
};
