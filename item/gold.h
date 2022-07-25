#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"

class Gold : public Item {
    private:
        int value;
    public:
        Gold();
        int getGold();
        void onPickup(Player *player) override;
};

#endif

