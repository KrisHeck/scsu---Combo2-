#pragma once

#include "Domino.h"
#include <vector>

class CDominoes {
private:
    std::vector<Domino> all;
    std::vector<Domino> boneyard;

public:
    void create_dominoes();
    std::vector<Domino>& pieces();
    const std::vector<Domino>& pieces() const;
    void setBoneyard(const std::vector<Domino>& by);
    bool canDraw() const;
    Domino draw();
    int boneyardSize() const;
    void printBoneyard() const;
};
