#ifndef _RNG_H_
#define _RNG_H_
#include <chrono>

class RNG {
    protected:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    public:
        int generateInt(int end, int start = 0);
};

#endif
