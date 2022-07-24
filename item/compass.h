#ifndef _COMPASS_H_
#define _COMPASS_H_
#include "item.h"

class Compass : public Item {
    public:
        void onPickup(Player *player) override;
};

#endif

