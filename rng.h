#ifndef _RNG_H_
#define _RNG_H_
#include <chrono>

class RNG {
    protected:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    public:
        RNG();
        static int generateInt(int n);
}

#endif
