#include "rng.h"
#include <random>

int RNG::generateInt(int end, int start) {
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<> distr(start, end);
    return distr(rng);
}
