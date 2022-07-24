#ifndef _ITEM_H_
#define _ITEM_H_
#include "../character/player/player.h"

class Item {
    protected:
        int uuid;
        int positionX;
        int positionY;
  
    public:
        virtual void onPickup(Player::Player *player) = 0;
        int getId();
};

#endif
