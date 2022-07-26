#include "rng.h"
#include <chrono>
#include <random>

int RNG::generateInt(int end, int start) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<> distr(start, end);
    return distr(rng);
}
