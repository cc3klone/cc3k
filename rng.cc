#include "rng.h"
#include <random>

static int RNG::generateInt(int end, int start) { //there are errors here
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<> distr(start, end);
    return distr(rng);
}
