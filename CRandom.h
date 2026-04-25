#pragma once

#include <stdlib.h>
#include <time.h>
#include <vector>

class CRandom {
public:
    CRandom();

    template <typename T>
    void shuffleVec(std::vector<T>& v) {
        for (int i = static_cast<int>(v.size()) - 1; i > 0; --i) {
            int j = randInt(0, i);
            T temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int randInt(int lo, int hi);
};
