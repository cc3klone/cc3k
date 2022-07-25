#ifndef _RNG_H_
#define _RNG_H_
#include <random>
#include <chrono>

class RNG {
    protected:
        unsigned seed;
    public:
        RNG();
        static int generateInt(int n);
}

#endif
