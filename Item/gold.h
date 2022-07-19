#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"

class Gold : public Item {
    const static bool passive = false;
    const static bool consumable = true;
    int value;

    public:
        void passiveEffect();
        void consumableEffect();
};

#endif

