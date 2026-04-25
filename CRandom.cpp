#include "CRandom.h"

CRandom::CRandom() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned>(time(NULL)));
        seeded = true;
    }
}

int CRandom::randInt(int lo, int hi) {
    if (hi < lo) return lo;
    return lo + (rand() % (hi - lo + 1));
}
