#pragma once

#include <stdio.h>

struct Domino {
    int left;
    int right;

    Domino() : left(0), right(0) {}
    Domino(int a, int b) : left(a), right(b) {}

    int sum() const { return left + right; }
    bool isDouble() const { return left == right; }

    void flip() {
        int temp = left;
        left = right;
        right = temp;
    }

    void print() const {
        printf("[%d|%d]", left, right);
    }

    void printAscii() const {
        printf("+---+\n|%d %d|\n+---+\n", left, right);
    }
};
