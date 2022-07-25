#include "rng.h"
#include <random>

static int RNG::generateInt(int end, int start = 0) {
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<> distr(start, end);
    return distr(rng);
}
