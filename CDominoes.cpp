#include "CDominoes.h"
#include <stdio.h>

void CDominoes::create_dominoes() {
    all.clear();
    boneyard.clear();

    for (int i = 0; i <= 6; ++i) {
        for (int j = i; j <= 6; ++j) {
            all.push_back(Domino(i, j));
        }
    }
}

std::vector<Domino>& CDominoes::pieces() { return all; }
const std::vector<Domino>& CDominoes::pieces() const { return all; }
void CDominoes::setBoneyard(const std::vector<Domino>& by) { boneyard = by; }
bool CDominoes::canDraw() const { return !boneyard.empty(); }

Domino CDominoes::draw() {
    Domino d = boneyard.back();
    boneyard.pop_back();
    return d;
}

int CDominoes::boneyardSize() const { return static_cast<int>(boneyard.size()); }

void CDominoes::printBoneyard() const {
    printf("Boneyard(%d): ", boneyardSize());
    for (size_t i = 0; i < boneyard.size(); ++i) {
        boneyard[i].print();
        printf(" ");
    }
    printf("\n");
}
