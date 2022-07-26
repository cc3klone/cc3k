#include "rng.h"
#include <chrono>
#include <random>

int RNG::generateInt(int end, int start) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng{seed};
    std::uniform_int_distribution<> distr(start, end);
    return distr(rng);
}
