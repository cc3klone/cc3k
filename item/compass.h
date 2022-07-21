#ifndef _COMPASS_H_
#define _COMPASS_H_
#include "item.h"

class Compass : public Item {
    const static bool passive = true;
    const static bool consumable = false;

    public:
        void passiveEffect() override;
};

#endif

