#ifndef _BARRIERSUIT_H_
#define _BARRIERSUIT_H_
#include "item.h"

class BarrierSuit : public Item {
    public:
        void onPickup(Player *player) override;
};

#endif

