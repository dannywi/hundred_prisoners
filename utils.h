#pragma once

#include <algorithm>
#include <random>

namespace hundred {

template<typename IT>
void shuffle(IT st, IT en) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(st, en, g);
}

}