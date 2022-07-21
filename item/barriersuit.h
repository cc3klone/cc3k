#ifndef _BARRIERSUIT_H_
#define _BARRIERSUIT_H_
#include "item.h"

class BarrierSuit : public Item {
    const static bool passive = true;
    const static bool consumable = false;

    public:
        void passiveEffect() override;
};

#endif

