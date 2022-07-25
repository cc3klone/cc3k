#include "rng.h"
#include <random>

static int RNG::generateInt(int n) {
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<> distr(0, n);
    return distr(rng);
}
