#ifndef _ITEM_H_
#define _ITEM_H_
#include "../character/player/player.h"
#include "../character/enemy/enemy.h"

class Item {
    protected:
        const int uuid;
        Enemy *guardingEnemy;
  
    public:
        virtual void onPickup(Player *player) = 0;
        int getId();
        Enemy *getGuardingEnemy();
        void setGuardingEnemy(Enemy *guardingEnemy);
};

#endif
